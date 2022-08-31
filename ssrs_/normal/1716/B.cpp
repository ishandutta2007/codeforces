#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        a[j][k] = k;
      }
    }
    for (int j = 0; j < n - 1; j++){
      a[j + 1] = a[j];
      swap(a[j + 1][0], a[j + 1][j + 1]);
    }
    cout << n << endl;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cout << a[j][k] + 1;
        if (k < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}