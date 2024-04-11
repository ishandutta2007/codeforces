#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
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
vector<long long> mf;
long long modfact(long long n){
	if (n < mf.size()){
		return mf[n];
	} else {
		if (mf.empty()) mf.push_back(1);
		long long res = mf.back();
		for (int i = mf.size(); i <= n; i++){
			res = res * i % MOD;
			mf.push_back(res);
		}
		return res;
	}
}
long long dfs(vector<vector<int>> &c, int v){
  long long ans = modfact(c[v].size());
  for (auto w : c[v]){
    ans *= dfs(c, w) * (c[w].size() + 1) % MOD;
    ans %= MOD;
  }
  return ans;
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
  cout << dfs(c, 0) * n % MOD << endl;
}