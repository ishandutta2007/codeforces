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
    int mx = 0;
    for (auto P : mp){
      mx = max(mx, P.second);
    }
    int ans = 0;
    while (mx < n){
      ans++;
      ans += min(mx, n - mx);
      mx += mx;
    }
    cout << ans << endl;
  }
}