#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  if (N <= 2){
    cout << -1 << endl;
  } else if (N == 3){
    cout << "1 2 7" << endl;
    cout << "4 3 9" << endl;
    cout << "8 5 6" << endl;
  } else if (N % 2 == 0){
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        int c;
        if (i == 0){
          c = N - j;
        } else if (i < N - 1 && j < N - 1){
          if (i % 2 == 0){
            c = (i + 1) * (N - 1) + 1 - j;
          } else {
            c = i * (N - 1) + 2 + j;
          }
        } else if (i == N - 1 && j > 0){
          c = (N - 1) * (N - 1) + 1 + j;
        } else if (j == N - 1 && i < N - 2){
          c = N * (N - 1) + 1 + i;
        } else if (i == N - 1){
          c = N * N - 1;
        } else {
          c = N * N;
        }
        cout << c;
        if (j < N - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        int c;
        if (i == 0){
          c = N - j;
        } else if (i == 1 && j == 0){
          c = N + 1;
        } else if (i >= 2 && i < N - 1 && j < N - 1){
          if (i % 2 == 0){
            c = N + (N - 1) * (i - 2) + 2 + j;
          } else {
            c = N + (N - 1) * (i - 1) + 1 - j;
          }
        } else if (i == N - 1 && j != 0 && j != N - 1){
          if (j % 2 == 0){
            c = (N - 1) * (N - 2) + 2 + 4 * (j / 2);
          } else {
            c = (N - 1) * (N - 2) + 3 + 4 * (j / 2);
          }
        } else if (i == 1 && j != 0 && j != N - 1){
          if (j % 2 == 0){
            c = (N - 1) * (N - 2) + 1 + 4 * (j / 2);
          } else {
            c = (N - 1) * (N - 2) + 4 + 4 * (j / 2);
          }
        } else if (i == 1 && j == N - 1){
          c = N * (N - 1) + 1;
        } else if (i == N - 1 && j == N - 1){
          c = N * (N - 1) + 2;
        } else if (j == N - 1 && i >= 2 && i < N - 2){
          c = N * (N - 1) + 1 + i;
        } else if (i == N - 1 && j == 0){
          c = N * N - 1;
        } else {
          c = N * N;
        }
        cout << c;
        if (j < N - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}