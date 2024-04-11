#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<long long> g(m);
  for (int i = 0; i < m; i++){
    cin >> g[i];
  }
  sort(b.begin(), b.end(), greater<long long>());
  sort(g.begin(), g.end());
  if (g[0] < b[0]){
    cout << -1 << endl;
  } else {
    long long ans = 0;
    for (int i = 0; i < n; i++){
      ans += b[i] * m;
    }
    if (g[0] == b[0]){
      for (int i = 0; i < m; i++){
        ans += g[i] - b[0];
      }
      cout << ans << endl;
    } else {
      if (g[m - 1] < b[1]){
        cout << -1 << endl;
      } else {
        for (int i = 1; i < m; i++){
          ans += g[i] - b[0];
        }
        ans += g[0] - b[1];
        cout << ans << endl;
      }
    }
  }
}