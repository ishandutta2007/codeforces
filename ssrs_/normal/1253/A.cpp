#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> d(n);
    for (int j = 0; j < n; j++){
      d[j] = b[j] - a[j];
    }
    int mx = 0;
    int mn = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, d[j]);
      mn = min(mn, d[j]);
    }
    if (mn < 0){
      cout << "NO" << endl;
    } else if (mx == 0){
      cout << "YES" << endl;
    } else {
      int l;
      for (int j = 0; j < n; j++){
        if (d[j] != 0){
          l = j;
          break;
        }
      }
      int r;
      for (int j = n - 1; j >= 0; j--){
        if (d[j] != 0){
          r = j;
          break;
        }
      }
      bool ok = true;
      for (int j = l; j <= r; j++){
        if (d[j] != mx){
          ok = false;
        }
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}