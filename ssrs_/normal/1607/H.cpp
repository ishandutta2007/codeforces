#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n), b(n), m(n);
    for (int j = 0; j < n; j++){
      cin >> a[j] >> b[j] >> m[j];
    }
    vector<int> S(n);
    for (int j = 0; j < n; j++){
      S[j] = a[j] + b[j] - m[j];
    }
    map<int, vector<int>> mp;
    for (int j = 0; j < n; j++){
      mp[S[j]].push_back(j);
    }
    vector<int> x(n), y(n);
    int ans = 0;
    for (auto &P : mp){
      vector<int> id = P.second;
      int cnt = id.size();
      vector<int> L(cnt), R(cnt);
      for (int j = 0; j < cnt; j++){
        L[j] = max(a[id[j]] - m[id[j]], 0);
        R[j] = a[id[j]];
        if (b[id[j]] < m[id[j]]){
          R[j] -= m[id[j]] - b[id[j]];
        }
      }
      vector<pair<int, int>> p(cnt);
      for (int j = 0; j < cnt; j++){
        p[j] = make_pair(R[j], L[j]);
      }
      sort(p.begin(), p.end());
      int mx = -1;
      vector<int> r;
      for (int j = 0; j < cnt; j++){
        if (mx < p[j].second){
          mx = p[j].first;
          r.push_back(mx);
        }
      }
      ans += r.size();
      for (int j = 0; j < cnt; j++){
        int c = upper_bound(r.begin(), r.end(), R[j]) - r.begin() - 1;
        x[id[j]] = a[id[j]] - r[c];
        y[id[j]] = m[id[j]] - x[id[j]];
      }
    }
    cout << ans << "\n";
    for (int j = 0; j < n; j++){
      cout << x[j] << ' ' << y[j] << "\n";
    }
  }
}