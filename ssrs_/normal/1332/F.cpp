#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long modsub(long long a, long long b){
	a %= MOD;
	b %= MOD;
	if (a >= b){
		return (a - b) % MOD;
	} else {
		return MOD - (b - a) % MOD;
	}
}
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
array<long long, 5> dfs(vector<vector<int>> &c, int v){
  if (c[v].empty()){
    return {0, 0, 0, 1, 1};
  } else {
    array<long long, 5> ans = {1, 1, 1, 1, 1};
    for (int w : c[v]){
      array<long long, 5> C = dfs(c, w);
      ans[0] = ans[0] * (C[0] + C[1] + C[2] + 1) % MOD;
      ans[1] = ans[1] * (C[0] + C[1] * 2 + C[2] * 2 + C[3] + C[4] + 1) % MOD;
      ans[2] = ans[2] * (C[0] + C[1] * 2 + C[2] + C[3] + 1) % MOD;
      ans[3] = ans[3] * (C[0] + C[1] + C[2] + 1) % MOD;
      ans[4] = ans[4] * (C[0] + C[1] + C[2] + 1) % MOD;
    }
    ans[0] = modsub(ans[0], 1);
    ans[1] = modsub(ans[1], ans[3]);
    ans[2] = modsub(ans[2], ans[4]);
    return ans;
  }
}
int main(){
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
  vector<vector<int>> c = child(E, 0);
  array<long long, 5> ans = dfs(c, 0);
  cout << (ans[0] + ans[1] + ans[2]) % MOD << endl;
}