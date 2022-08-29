#include <bits/stdc++.h>
using namespace std;
long long INF = 10000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--;
    b--;
    c--;
    vector<int> p(m);
    for (int j = 0; j < m; j++){
      cin >> p[j];
    }
    sort(p.begin(), p.end());
    vector<long long> S(m + 1, 0);
    for (int j = 0; j < m; j++){
      S[j + 1] = S[j] + p[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    long long ans = INF;
    queue<int> Q;
    vector<int> A(n, -1);
    A[a] = 0;
    Q.push(a);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (A[w] == -1){
          A[w] = A[v] + 1;
          Q.push(w);
        }
      }
    }
    vector<int> B(n, -1);
    B[b] = 0;
    Q.push(b);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (B[w] == -1){
          B[w] = B[v] + 1;
          Q.push(w);
        }
      }
    }
    vector<int> C(n, -1);
    C[c] = 0;
    Q.push(c);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (C[w] == -1){
          C[w] = C[v] + 1;
          Q.push(w);
        }
      }
    }
    for (int j = 0; j < n; j++){
      int two = B[j];
      int one = A[j] + C[j];
      if (one + two <= m){
        long long cost = S[two] + S[one + two];
        ans = min(ans, cost);
      }
    }
    cout << ans << endl;
  }
}