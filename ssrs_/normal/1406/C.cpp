#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int> &dp, vector<vector<int>> &c, int v = 0){
  for (int w : c[v]){
    dp[v] += dfs(dp, c, w);
  }
  return dp[v];
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      E[x].push_back(y);
      E[y].push_back(x);

    }
    if (n % 2 == 1){
      int a = 1;
      int b = E[0][0] + 1;
      cout << a << ' ' << b << endl;
      cout << a << ' ' << b << endl;
    } else {
      vector<int> p(n, -1);
      vector<vector<int>> c(n);
      queue<int> Q;
      Q.push(0);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (w != p[v]){
            p[w] = v;
            c[v].push_back(w);
            Q.push(w);
          }
        }
      }
      vector<int> dp(n, 1);
      dfs(dp, c);
      int cut = -1;
      for (int j = 0; j < n; j++){
        if (dp[j] == n / 2){
          cut = j;
        }
      }
      if (cut == -1){
        int a = 1;
        int b = E[0][0] + 1;
        cout << a << ' ' << b << endl;
        cout << a << ' ' << b << endl;
      } else {
        int v = cut;
        while (!c[v].empty()){
          v = c[v][0];
        }
        cout << v + 1 << ' ' << p[v] + 1 << endl;
        cout << v + 1 << ' ' << p[cut] + 1 << endl;
      }
    }
  }
}