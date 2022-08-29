#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<int> p(n, -1);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  bool ok = true;
  for (int i = 1; i < n; i++){
    if (s[i] != -1){
      if (s[i] < s[p[p[i]]]){
        ok = false;
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    vector<vector<int>> c(n);
    for (int i = 1; i < n; i++){
      c[p[i]].push_back(i);
    }
    vector<int> a(n);
    a[0] = s[0];
    for (int i = 1; i < n; i++){
      if (s[i] == -1){
        if (c[i].empty()){
          a[i] = 0;
        } else {
          a[i] = INF;
          for (int w : c[i]){
            a[i] = min(a[i], s[w] - s[p[i]]);
          }
          s[i] = s[p[i]] + a[i];
        }
      } else {
        a[i] = s[i] - s[p[i]];
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++){
      ans += a[i];
    }
    cout << ans << endl;
  }
}