#include <bits/stdc++.h>
using namespace std;
int MAX = 15000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int g = 0;
  for (int i = 0; i < n; i++){
    g = __gcd(g, a[i]);
  }
  for (int i = 0; i < n; i++){
    a[i] /= g;
  }
  vector<int> fact(MAX + 1, -1);
  for (int i = 2; i <= MAX; i++){
    if (fact[i] == -1){
      for (int j = i; j <= MAX; j += i){
        if (fact[j] == -1){
          fact[j] = i;
        }
      }
    }
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    while (a[i] != 1){
      int x = fact[a[i]];
      while (a[i] % x == 0){
        a[i] /= x;
      }
      mp[x]++;
    }
  }
  int ans = n;
  for (auto P : mp){
    ans = min(ans, n - P.second);
  }
  if (ans == n){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}