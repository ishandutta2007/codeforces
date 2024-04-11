#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> A(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    A[0][i] = a[i];
  }
  for (int i = 1; i < n; i++){
    for (int j = 0; j < n - i; j++){
      A[i][j] = A[i - 1][j] ^ A[i - 1][j + 1];
    }
  }
  vector<vector<int>> B(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    B[0][i] = a[i];
  }
  for (int i = 1; i < n; i++){
    for (int j = 0; j < n - i; j++){
      B[i][j] = max(A[i][j], max(B[i - 1][j], B[i - 1][j + 1]));
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    int d = r - l;
    l--;
    cout << B[d][l] << "\n";
  }
}