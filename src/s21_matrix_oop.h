#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

#define EPS 1e-7
#define S_AR 1

class S21Matrix {
 public:
  // конструкторы деструкторы
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(S21Matrix &&other);  // конструктор перемещения
  S21Matrix(const S21Matrix &other);  // конструктор копирования
  ~S21Matrix();

  // методы
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);        // умножение на число
  void MulMatrix(const S21Matrix &other);  // умножение матриц
  S21Matrix Transpose();
  S21Matrix CalcComplements();  // Вычисляет матрицу алгебраических дополнений
                                // текущей матрицы и возвращает ее
  S21Matrix Submatrix(int row, int col);
  double Determinant();  // Вычисляет и возвращает определитель текущей матрицы
  S21Matrix InverseMatrix();  // Вычисляет и возвращает обратную матрицу

  // операторы
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator=(const S21Matrix &other);
  S21Matrix operator=(S21Matrix &&other);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double num);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num);
  double &operator()(int rows, int columns);

  // ассесоры мутаторы
  int GetRows() const;
  int GetCols() const;

  void SetRows(int rows);
  void SetColumns(int columns);

  friend S21Matrix operator*(double num, S21Matrix &other);
  // void PrintMatrix();

 private:
  int rows_, cols_;
  double **matrix_;
  void CreateMatrix();
  void DestroyMatrix();
  void CopyMatrix(const S21Matrix &other);  // копирует матрицу в текущий объект
  void MoveMatrix(
      S21Matrix &other);  // перемещает, в целом как конструктор перемещ
  void SetNull();  // зануляет все, без освобождения памяти
  int EqualMatrix(const S21Matrix &other);
};

#endif  // CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H