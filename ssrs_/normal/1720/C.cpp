#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cnt += a[j][k] - '0';
      }
    }
    if (cnt == 0){
      cout << 0 << endl;
    } else {
      int mn = 4;
      for (int j = 0; j < n - 1; j++){
        for (int k = 0; k < m - 1; k++){
          mn = min(mn, (a[j][k] - '0') + (a[j][k + 1] - '0') + (a[j + 1][k] - '0'));
          mn = min(mn, (a[j][k] - '0') + (a[j][k + 1] - '0') + (a[j + 1][k + 1] - '0'));
          mn = min(mn, (a[j][k] - '0') + (a[j + 1][k + 1] - '0') + (a[j + 1][k] - '0'));
          mn = min(mn, (a[j + 1][k + 1] - '0') + (a[j][k + 1] - '0') + (a[j + 1][k] - '0'));
        }
      }
      if (mn == 0){
        mn = 1;
      }
      cout << cnt - mn + 1 << endl;
    }
  }
}