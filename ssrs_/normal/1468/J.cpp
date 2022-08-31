#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int N){
    p = vector<int>(N, -1);
  }
  int root(int x){
    if (p[x] < 0){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      if (p[x] > p[y]){
        swap(x, y);
      }
      p[x] += p[y];
      p[y] = x;
    }
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(m), y(m), s(m);
    for (int j = 0; j < m; j++){
      cin >> x[j] >> y[j] >> s[j];
      x[j]--;
      y[j]--;
    }
    vector<tuple<int, int, int>> E(m);
    for (int j = 0; j < m; j++){
      E[j] = make_tuple(s[j], x[j], y[j]);
    }
    sort(E.begin(), E.end());
    unionfind UF(n);
    long long ans = 0;
    bool ok = false;
    for (int j = 0; j < m; j++){
      int u = get<1>(E[j]);
      int v = get<2>(E[j]);
      if (!UF.same(u, v)){
        ans += max(get<0>(E[j]) - k, 0);
        UF.unite(u, v);
        if (get<0>(E[j]) >= k){
          ok = true;
        }
      }
    }
    if (!ok){
      if (get<0>(E[m - 1]) >= k){
        int p = lower_bound(E.begin(), E.end(), make_tuple(k, -1, -1)) - E.begin();
        ans += get<0>(E[p]) - k;
        ok = true;
      }
    }
    int mx = 0;
    vector<vector<int>> E2(n);
    for (int j = 0; j < m; j++){
      if (s[j] < k){
        E2[x[j]].push_back(y[j]);
        E2[y[j]].push_back(x[j]);
        mx = max(mx, s[j]);
      }
    }
    vector<bool> used(n, false);
    used[0] = true;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E2[v]){
        if (!used[w]){
          used[w] = true;
          Q.push(w);
        }
      }
    }
    bool ok2 = true;
    for (int j = 1; j < n; j++){
      if (!used[j]){
        ok2 = false;
      }
    }
    if (ok2){
      if (!ok){
        ans = k - mx;
      } else {
        ans = min(ans, (long long) k - mx);
      }
    }
    cout << ans << endl;
  }
}