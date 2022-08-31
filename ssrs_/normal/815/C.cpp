#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
void dfs1(vector<int> &sz, vector<vector<int>> &ch, int v){
  sz[v] = 1;
  for (int w : ch[v]){
    dfs1(sz, ch, w);
    sz[v] += sz[w];
  }
}
vector<long long> merge(vector<long long> A, vector<long long> B){
  int N = A.size();
  int M = B.size();
  vector<long long> ans(N + M - 1, INF);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      ans[i + j] = min(ans[i + j], A[i] + B[j]);
    }
  }
  return ans;
}
vector<long long> min(vector<long long> &A, vector<long long> &B){
  int N = A.size();
  vector<long long> ans(N);
  for (int i = 0; i < N; i++){
    ans[i] = min(A[i], B[i]);
  }
  return ans;
}
void dfs2(vector<vector<vector<long long>>> &dp, vector<vector<int>> &ch, vector<int> &sz, vector<long long> &c, vector<long long> &d, int v){
  for (int w : ch[v]){
    dfs2(dp, ch, sz, c, d, w);
  }
  //dp[v][0]
  dp[v][0] = {0, c[v]};
  for (int w : ch[v]){
    dp[v][0] = merge(dp[v][0], dp[w][0]);
  }
  //dp[v][1]
  dp[v][1] = {INF, c[v] - d[v]};
  for (int w : ch[v]){
    dp[v][1] = merge(dp[v][1], min(dp[w][0], dp[w][1]));
  }
}
int main(){
  int n;
  long long b;
  cin >> n >> b;
  vector<long long> c(n), d(n);
  vector<int> x(n);
  x[0] = -1;
  for (int i = 0; i < n; i++){
    cin >> c[i] >> d[i];
    if (i > 0){
      cin >> x[i];
      x[i]--;
    }
  }
  vector<vector<int>> ch(n);
  for (int i = 0; i < n; i++){
    if (x[i] != -1){
      ch[x[i]].push_back(i);
    }
  }
  vector<int> sz(n, 0);
  dfs1(sz, ch, 0);
  vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2));
  dfs2(dp, ch, sz, c, d, 0);
  /*
  for (int i = 0; i < n; i++){
    for (int j = 0; j < dp[i][0].size(); j++){
      cout << dp[i][0][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < dp[i][1].size(); j++){
      cout << dp[i][1][j] << ' ';
    }
    cout << endl;
  }
  */
  int ans1 = upper_bound(dp[0][0].begin(), dp[0][0].end(), b) - dp[0][0].begin() - 1;
  int ans2 = upper_bound(dp[0][1].begin(), dp[0][1].end(), b) - dp[0][1].begin() - 1;
  cout << max(ans1, ans2) << endl;
}