#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int main(){
  vector<int> m(MAX, -1);
  for (int i = 2; i < MAX; i++){
    if (m[i] == -1){
      for (int j = i * 2; j < MAX; j += i){
        m[j] = i;
      }
    }
  }
  vector<vector<int>> f(MAX);
  for (int i = 2; i < MAX; i++){
    int n = i;
    while (m[n] != -1){
      f[i].push_back(m[n]);
      n /= m[n];
    }
    f[i].push_back(n);
    sort(f[i].begin(), f[i].end());
    f[i].erase(unique(f[i].begin(), f[i].end()), f[i].end());
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int g = 0;
    for (int j = 0; j < n; j++){
      g = __gcd(g, a[j]);
    }
    for (int j = 0; j < n; j++){
      a[j] /= g;
    }
    map<int, vector<int>> mp;
    for (int j = 0; j < n; j++){
      for (int k : f[a[j]]){
        mp[k].push_back(j);
      }
    }
    int ans = 0;
    for (auto P : mp){
      int cnt = P.second.size();
      vector<bool> D(cnt);
      for (int j = 0; j < cnt; j++){
        int d;
        if (j < cnt - 1){
          d = P.second[j + 1] - P.second[j];
        } else {
          d = P.second[0] + n - P.second[j];
        }
        if (d == 1){
          D[j] = true;
        } else {
          D[j] = false;
        }
      }
      int c = 1;
      for (int j = 0; j < cnt * 2; j++){
        if (D[j % cnt]){
          c++;
        } else {
          c = 1;
        }
        ans = max(ans, c);
      }
    }
    cout << ans << endl;
  }
}