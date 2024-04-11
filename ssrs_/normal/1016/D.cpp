#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  long long A = 0;
  for (int i = 0; i < n; i++){
    A ^= a[i];
  }
  long long B = 0;
  for (int i = 0; i < m; i++){
    B ^= b[i];
  }
  if (A != B){
    cout << "NO" << endl;
  } else {
    vector<vector<long long>> c(n, vector<long long>(m, 0));
    long long X = b[m - 1];
    for (int i = 0; i < n - 1; i++){
      c[i][m - 1] = a[i];
      X ^= a[i];
    }
    for (int i = 0; i < m - 1; i++){
      c[n - 1][i] = b[i];
    }
    c[n - 1][m - 1] = X;
    cout << "YES"<< endl;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cout << c[i][j];
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}