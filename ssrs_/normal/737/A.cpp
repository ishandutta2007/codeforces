#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  long long s, t;
  cin >> n >> k >> s >> t;
  vector<int> c(n), v(n);
  for (int i = 0; i < n; i++){
    cin >> c[i] >> v[i];
  }
  vector<int> g(k);
  for (int i = 0; i < k; i++){
    cin >> g[i];
  }
  g.push_back(0);
  g.push_back(s);
  k += 2;
  sort(g.begin(), g.end());
  long long tv = INF;
  long long fv = 0;
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    long long time = 0;
    bool ok = true;
    for (int i = 0; i < k - 1; i++){
      long long d = g[i + 1] - g[i];
      if (mid < d){
        ok = false;
      } else if (mid > d * 2){
        time += d;
      } else {
        time += 3 * d - mid;
      }
    }
    if (ok && time <= t){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  long long ans = INF;
  for (int i = 0; i < n; i++){
    if (v[i] >= tv){
      ans = min(ans, (long long) c[i]);
    }
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}