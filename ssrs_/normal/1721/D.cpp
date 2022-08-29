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
    int ans = 0;
    for (int j = 29; j >= 0; j--){
      map<int, int> mp;
      for (int k = 0; k < n; k++){
        int a2 = a[k] & (ans | (1 << j));
        mp[a2]++;
        int b2 = (b[k] & (ans | (1 << j))) ^ (ans | (1 << j));
        mp[b2]--;
      }
      bool ok = true;
      for (auto P : mp){
        if (P.second != 0){
          ok = false;
        }
      }
      if (ok){
        ans |= 1 << j;
      }
    }
    cout << ans << endl;
  }
}