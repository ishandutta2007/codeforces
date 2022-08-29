#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(c[i], i);
  }
  sort(P.begin(), P.end());
  int p = 0;
  for (int i = 0; i < m; i++){
    int t, d;
    cin >> t >> d;
    t--;
    long long ans = 0;
    int tmp = min(d, a[t]);
    ans += (long long) c[t] * tmp;
    d -= tmp;
    a[t] -= tmp;
    while (d > 0 && p < n){
      int id = P[p].second;
      tmp = min(d, a[id]);
      ans += (long long) c[id] * tmp;
      d -= tmp;
      a[id] -= tmp;
      if (d == 0){
        break;
      }
      p++;
    }
    if (d != 0){
      cout << 0 << endl;
    } else {
      cout << ans << endl;
    }
  }
}