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
    bool same = true;
    int mx = 0;
    for (int j = 0; j < n; j++){
      if (a[j] != a[0]){
        same = false;
      }
      if (a[j] > mx){
        mx = a[j];
      }
    }
    if (same){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n; j++){
        if (a[j] == mx){
          bool ok = false;
          if (j > 0){
            if (a[j - 1] < mx){
              ok = true;
            }
          }
          if (j < n){
            if (a[j + 1] < mx){
              ok = true;
            }
          }
          if (ok){
            cout << j + 1 << endl;
            break;
          }
        }
      }
    }
  }
}