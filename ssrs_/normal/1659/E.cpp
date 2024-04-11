#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m), w(m);
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> w[i];
    a[i]--;
    b[i]--;
  }
  int q;
  cin >> q;
  vector<int> u(q), v(q);
  for (int i = 0; i < q; i++){
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  vector<int> ans(q, 2);
  for (int i = 0; i < 30; i++){
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      if ((w[j] >> i & 1) == 1){
        E[a[j]].push_back(b[j]);
        E[b[j]].push_back(a[j]);
      }
    }
    vector<int> cc(n, -1);
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (cc[j] == -1){
        cc[j] = cnt;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v2 = Q.front();
          Q.pop();
          for (int w2 : E[v2]){
            if (cc[w2] == -1){
              cc[w2] = cnt;
              Q.push(w2);
            }
          }
        }
        cnt++;
      }
    }
    for (int j = 0; j < q; j++){
      if (cc[u[j]] == cc[v[j]]){
        ans[j] = 0;
      }
    }
  }
  for (int i = 1; i < 30; i++){
    vector<vector<int>> E(n);
    vector<bool> ok(n, false);
    for (int j = 0; j < m; j++){
      if ((w[j] >> i & 1) == 1 && w[j] % 2 == 1){
        E[a[j]].push_back(b[j]);
        E[b[j]].push_back(a[j]);
      }
      if (w[j] % 2 == 0){
        ok[a[j]] = true;
        ok[b[j]] = true;
      }
    }
    vector<int> cc(n, -1);
    int cnt = 0;
    vector<bool> ok2;
    for (int j = 0; j < n; j++){
      if (cc[j] == -1){
        cc[j] = cnt;
        queue<int> Q;
        Q.push(j);
        ok2.push_back(false);
        while (!Q.empty()){
          int v2 = Q.front();
          Q.pop();
          if (ok[v2]){
            ok2.back() = true;
          }
          for (int w2 : E[v2]){
            if (cc[w2] == -1){
              cc[w2] = cnt;
              Q.push(w2);
            }
          }
        }
        cnt++;
      }
    }
    for (int j = 0; j < q; j++){
      if (ans[j] == 2){
        if (ok2[cc[u[j]]]){
          ans[j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}