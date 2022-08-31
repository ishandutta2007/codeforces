#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> child(vector<vector<int>> E, int r){
	int N = E.size();
	vector<vector<int>> c(N);
	queue<int> Q;
	Q.push(r);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int w : E[v]){
			if (c[w].empty()){
				c[v].push_back(w);
				Q.push(w);
			}
		}
	}
	return c;
}
int dfs(vector<vector<int>> &c, vector<int> &dp, int v){
  for (int w : c[v]){
    dp[v] += dfs(c, dp, w) + 1;
  }
  return dp[v];
}
void dfs2(vector<vector<int>> &c, vector<int> &dp, int v){
  for (int w: c[v]){
    dp[w] += (dp[v] + 1);
    dfs2(c, dp, w);
  }
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<vector<int>> c = child(E, 0);
  vector<int> dp(n, 0);
  dfs(c, dp, 0);
  vector<int> dp2(n, 0);
  dfs2(c, dp2, 0);
  vector<pair<int, int>> V(n);
  for (int i = 0; i < n; i++){
    V[i] = make_pair(dp2[i] - dp[i], i);
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  long long sum = 0;
  for (int i = 0; i < k; i++){
    sum += V[i].first;
  }
  cout << sum << endl;
}