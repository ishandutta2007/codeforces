#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    bool ok;
    if (n % 2 == 0 && m % 2 == 0){
      ok = k % 2 == 0;
    } else if (n % 2 == 1){
      ok = k % 2 == m / 2 % 2 && k >= m / 2;
    } else {
      ok = k % 2 == (n * m / 2 - n / 2) % 2 && k <= n * m / 2 - n / 2;
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      vector<vector<char>> c(n, vector<char>(m));
      for (int j = 0; j < n - 1; j += 2){
        for (int l = 0; l < m - 1; l += 2){
          if ((j + l) % 4 == 0){
            c[j][l] = 'a';
            c[j][l + 1] = 'b';
            c[j + 1][l] = 'a';
            c[j + 1][l + 1] = 'b';
          } else {
            c[j][l] = 'c';
            c[j][l + 1] = 'd';
            c[j + 1][l] = 'c';
            c[j + 1][l + 1] = 'd';
          }
        }
        if (m % 2 == 1){
          if (j % 4 == 0){
            c[j][m - 1] = 'e';
            c[j + 1][m - 1] = 'e';
          } else {
            c[j][m - 1] = 'f';
            c[j + 1][m - 1] = 'f';
          }
        }
      }
      if (n % 2 == 1){
        for (int j = 0; j < m; j += 2){
          if (j % 4 == 0){
            c[n - 1][j] = 'e';
            c[n - 1][j + 1] = 'e';
          } else {
            c[n - 1][j] = 'f';
            c[n - 1][j + 1] = 'f';
          }
          k--;
        }
      }
      for (int j = 0; j < n - 1; j += 2){
        for (int l = 0; l < m - 1; l += 2){
          if (k > 0){
            swap(c[j][l + 1], c[j + 1][l]);
            k -= 2;
          }
        }
      }
      cout << "YES" << endl;
      for (int j = 0; j < n; j++){
        for (int l = 0; l < m; l++){
          cout << c[j][l];
        }
        cout << endl;
      }
    }
  }
}