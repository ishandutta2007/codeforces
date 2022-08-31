#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
bool isfib(int N, vector<vector<int>> &E, vector<int> &pfib){
  if (N <= 3){
    return true;
  }
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  vector<int> b;
  b.reserve(N);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    b.push_back(v);
    for (int &w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(b.begin(), b.end());
  vector<int> dp(N, 1);
  for (int &v : b){
    for (int &w : c[v]){
      dp[v] += dp[w];
    }
  }
  int p1 = pfib[N];
  int p2 = pfib[p1];
  int cut = -1;
  for (int i = 0; i < N; i++){
    if (dp[i] == p1 || dp[i] == p2){
      cut = i;
      break;
    }
  }
  if (cut == -1){
    return false;
  }
  vector<bool> ch(N, false);
  queue<int> Q2;
  Q2.push(cut);
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    ch[v] = true;
    for (int w : c[v]){
      Q2.push(w);
    }
  }
  int cnt0 = 0, cnt1 = 0;
  vector<int> id(N, 0);
  for (int i = 0; i < N; i++){
    if (!ch[i]){
      id[i] = cnt0;
      cnt0++;
    } else {
      id[i] = cnt1;
      cnt1++;
    }
  }
  vector<vector<int>> E0(cnt0), E1(cnt1);
  for (int i = 0; i < N; i++){
    for (int j : E[i]){
      if (!ch[i] && !ch[j]){
        E0[id[i]].push_back(id[j]);
      }
      if (ch[i] && ch[j]){
        E1[id[i]].push_back(id[j]);
      }
    }
  }
  return isfib(cnt0, E0, pfib) && isfib(cnt1, E1, pfib);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> fib = {1, 1};
  while (fib.back() < n){
    int m = fib.size();
    int a = fib[m - 2], b = fib[m - 1];
    fib.push_back(a + b);
  }
  if (fib.back() != n){
    cout << "NO" << "\n";
  } else {
    int m = fib.size();
    vector<int> pfib(n + 1, -1);
    for (int i = 0; i < m - 1; i++){
      pfib[fib[i + 1]] = fib[i];
    }
    bool ok = isfib(n, E, pfib);
    if (ok){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}