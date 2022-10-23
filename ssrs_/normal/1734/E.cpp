#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      a[i][j] = i * j % n;
    }
    int c = (b[i] - a[i][i] + n) % n;
    for (int j = 0; j < n; j++){
      a[i][j] += c;
      a[i][j] %= n;
    }
  }
  for (int j = 0; j < n; j++){
    for (int k = 0; k < n; k++){
      cout << a[j][k];
      if (k < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}