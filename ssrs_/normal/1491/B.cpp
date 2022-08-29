#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    bool ok = false;
    for (int j = 0; j < n - 1; j++){
      if (abs(a[j + 1] - a[j]) >= 2){
        ok = true;
      }
    }
    if (ok){
      cout << 0 << "\n";
    } else {
      bool same = true;
      for (int j = 0; j < n; j++){
        if (a[j] != a[0]){
          same = false;
        }
      }
      if (!same){
        cout << min(u, v) << "\n";
      } else {
        cout << v + min(u, v) << "\n";
      }
    }
  }
}