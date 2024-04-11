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
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[a[j]]++;
    }
    bool ok = false;
    for (auto P : mp){
      if (P.second >= n / 2){
        ok = true;
      }
    }
    if (ok){
      cout << -1 << endl;
    } else {
      int ans = 0;
      for (int j = 0; j < n; j++){
        vector<int> b;
        for (int k = 0; k < n; k++){
          if (k != j){
            b.push_back(abs(a[k] - a[j]));
          }
        }
        vector<int> F;
        for (int k = 0; k < n - 1; k++){
          for (int l = 1; l * l <= b[k]; l++){
            if (b[k] % l == 0){
              F.push_back(l);
              F.push_back(b[k] / l);
            }
          }
        }
        sort(F.begin(), F.end());
        F.erase(unique(F.begin(), F.end()), F.end());
        for (int x : F){
          int cnt = 0;
          for (int k = 0; k < n - 1; k++){
            if (b[k] % x == 0){
              cnt++;
            }
          }
          if (cnt + 1 >= n / 2){
            ans = max(ans, x);
          }
        }
      }
      cout << ans << endl;
    }
  }
}