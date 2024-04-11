#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    E[a[i]].push_back(make_pair(i, b[i]));
    E[b[i]].push_back(make_pair(i, a[i]));
  }
  bool ok = true;
  vector<long long> ans(m, 0);
  vector<int> C(n, -1);
  vector<int> pr(n, -1);
  vector<int> pi(n, -1);
  for (int i = 0; i < n; i++){
    if (C[i] == -1){
      C[i] = 0;
      queue<int> Q;
      Q.push(i);
      int e = -1;
      vector<long long> sum(2, 0);
      vector<int> bfs;
      while (!Q.empty()){
        int v = Q.front();
        bfs.push_back(v);
        Q.pop();
        sum[C[v]] += c[v];
        for (pair<int, int> P : E[v]){
          int w = P.second;
          if (C[w] == -1){
            C[w] = 1 - C[v];
            pr[w] = v;
            pi[w] = P.first;
            Q.push(w);
          } else if (C[w] == C[v]){
            e = P.first;
          }
        }
      }
      if (e != -1){
        ans[e] = (sum[C[a[e]]] - sum[1 - C[a[e]]]) / 2;
        c[a[e]] -= ans[e];
        c[b[e]] -= ans[e];
      }
      int V = bfs.size();
      for (int j = V - 1; j >= 1; j--){
        ans[pi[bfs[j]]] = c[bfs[j]];
        c[pr[bfs[j]]] -= c[bfs[j]];
      }
      if (c[bfs[0]] != 0){
        ok = false;
      }
    }
  }
  if (ok){
    cout << "YES" << endl;
    for (int i = 0; i < m; i++){
      cout << ans[i] << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}