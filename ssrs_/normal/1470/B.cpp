#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> rs(1000001);
  for (int i = 0; i <= 1000000; i++){
    rs[i] = i;
  }
  for (int i = 2; i <= 1000; i++){
    if (rs[i * i] == i * i){
      for (int j = i * i; j <= 1000000; j += i * i){
        while (rs[j] % (i * i) == 0){
          rs[j] /= i * i;
        }
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j] = rs[a[j]];
    }
    unordered_map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[a[j]]++;
    }
    int ans1 = 0;
    for (auto P : mp){
      ans1 = max(ans1, P.second);
    }
    int ans2 = 0;
    for (auto P : mp){
      if (P.second % 2 == 0 || P.first == 1){
        ans2 += P.second;
      }
    }
    ans2 = max(ans1, ans2);
    int q;
    cin >> q;
    for (int j = 0; j < q; j++){
      long long w;
      cin >> w;
      if (w == 0){
        cout << ans1 << "\n";
      } else {
        cout << ans2 << "\n";
      }
    }
  }
}