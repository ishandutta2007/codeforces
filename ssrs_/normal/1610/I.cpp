#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  queue<int> Q;
  Q.push(0);
  vector<int> bfs;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<int> dp(n, 0);
  for (int v : bfs){
    for (int w : c[v]){
      dp[v] ^= dp[w] + 1;
    }
  }
  vector<bool> used(n, false);
  used[0] = true;
  vector<int> ans(n);
  vector<int> cnt(n);
  ans[0] = dp[0];
  cnt[0] = 0;
  for (int i = 1; i < n; i++){
    ans[i] = ans[i - 1];
    cnt[i] = cnt[i - 1];
    int v = i;
    while (!used[v]){
      used[v] = true;
      cnt[i]++;
      ans[i] ^= dp[v] + 1;
      ans[i] ^= dp[v];
      v = p[v];
    }
  }
  for (int i = 0; i < n; i++){
    if ((ans[i] ^ (cnt[i] % 2)) == 0){
      cout << 2;
    } else {
      cout << 1;
    }
  }
  cout << endl;
}