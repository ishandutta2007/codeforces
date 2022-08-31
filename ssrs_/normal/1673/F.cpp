#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> gray;
  gray.push_back(0);
  for (int i = 1; i < 32; i++){
    int p = gray.back();
    p ^= 1 << (__builtin_ctz(i) * 2);
    gray.push_back(p);
  }
  int n, k;
  cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      A[i][j] = gray[i] + gray[j] * 2;
    }
  }
  vector<int> X(1024), Y(1024);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      X[A[i][j]] = i;
      Y[A[i][j]] = j;
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n - 1; j++){
      cout << (A[i][j] ^ A[i][j + 1]);
      if (j < n - 2){
        cout << ' ';
      }
    }
    cout << endl;
  }
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n; j++){
      cout << (A[i][j] ^ A[i + 1][j]);
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
  int r = 0, c = 0;
  for (int i = 0; i < k; i++){
    int x;
    cin >> x;
    x ^= A[r][c];
    r = X[x];
    c = Y[x];
    cout << r + 1 << ' ' << c + 1 << endl;
  }
}