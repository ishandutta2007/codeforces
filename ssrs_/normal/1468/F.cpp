#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n), y(n), u(n), v(n);
    for (int j = 0; j < n; j++){
      cin >> x[j] >> y[j] >> u[j] >> v[j];
    }
    map<pair<int, int>, int> mp;
    for (int j = 0; j < n; j++){
      int dx = u[j] - x[j];
      int dy = v[j] - y[j];
      int g = __gcd(abs(dx), abs(dy));
      dx /= g;
      dy /= g;
      mp[make_pair(dx, dy)]++;
    }
    long long ans = 0;
    for (auto P : mp){
      int dx = P.first.first;
      int dy = P.first.second;
      if (mp.count(make_pair(-dx, -dy))){
        ans += (long long) P.second * mp[make_pair(-dx, -dy)];
      }
    }
    ans /= 2;
    cout << ans << endl;
  }
}