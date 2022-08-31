#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    map<long long, int> mp;
    for (int i = 0; i < n; i++){
      mp[a[i]]++;
    }
    long long ans = n;
    for (auto P : mp){
      if (mp.count(P.first * x) == 1){
        int mn = min(P.second, mp[P.first * x]);
        ans -= mn * 2;
        mp[P.first * x] -= mn;
      }
    }
    cout << ans << "\n";
  }
}