#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> A = {0, 1};
  vector<int> B = {1};
  for (int i = 0; i < n - 1; i++){
    vector<int> A2(i + 3, 0), B2(i + 2, 0);
    for (int j = 0; j < i + 2; j++){
      A2[j + 1] += A[j];
      B2[j] += A[j];
    }
    bool ok_p = true, ok_n = true;
    for (int j = 0; j < i + 1; j++){
      if (abs(A2[j] - B[j]) == 2){
        ok_n = false;
      }
      if (abs(A2[j] + B[j]) == 2){
        ok_p = false;
      }
    }
    assert(ok_p || ok_n);
    if (ok_p){
      for (int j = 0; j < i + 1; j++){
        A2[j] += B[j];
      }
    } else {
      for (int j = 0; j < i + 1; j++){
        A2[j] -= B[j];
      }
    }
    A = A2;
    B = B2;
  }
  cout << n << endl;
  for (int i = 0; i <= n; i++){
    cout << A[i];
    if (i < n){
      cout << ' ';
    }
  }
  cout << endl;
  cout << n - 1 << endl;
  for (int i = 0; i < n; i++){
    cout << B[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}