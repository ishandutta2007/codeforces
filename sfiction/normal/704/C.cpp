#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;

const int MAXN = 1E5 + 10, MAXM = 1E5 + 10;
const ll MOD = 1E9 + 7;

int n, m;
bool vis[MAXM];
vector<PIP> E[MAXM];
vector<int> G[MAXM];

void solve(int init, vector<PII> &a, ll res[2][2]){
	static ll dp[2][2][2];
	memset(dp[0], 0, sizeof dp[0]);
	dp[0][init][0] = 1;
	for (int i = 0; i < a.size(); ++i){
		memset(dp[i + 1 & 1], 0, sizeof dp[0]);
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l)
					dp[i + 1 & 1][l][k ^ (j ^ a[i].st < 0 | l ^ a[i].nd < 0)] += dp[i & 1][j][k];
		dp[i + 1 & 1][0][0] %= MOD;
		dp[i + 1 & 1][0][1] %= MOD;
		dp[i + 1 & 1][1][0] %= MOD;
		dp[i + 1 & 1][1][1] %= MOD;
	}
	memcpy(res, dp[a.size() & 1], sizeof dp[0]);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int k, u, v, i = 0; i < n; ++i){
		scanf("%d%d", &k, &u);
		if (k == 1)
			G[abs(u)].push_back(u);
		else{
			scanf("%d", &v);
			E[abs(u)].push_back(PIP(abs(v), PII(u, v)));
			E[abs(v)].push_back(PIP(abs(u), PII(v, u)));
		}
	}

	vector<PII> res;
	ll b[2][2];
	for (int i = 1; i <= m; ++i)
		if (E[i].size() == 0){
			if (G[i].size() == 0)
				res.push_back(PII(2, 0));
			else if (G[i].size() == 1)
				res.push_back(PII(1, 1));
			else if (G[i].size() == 2)
				res.push_back(G[i][0] > 0 == G[i][1] > 0 ? PII(2, 0) : PII(0, 2));
		}
		else if (E[i].size() == 1 && !vis[i]){
			vector<PII> a;
			a.push_back(E[i][0].nd);
			for (int u = E[i][0].st; E[u].size() > 1; u = abs(a.back().nd)){
				vis[u] = true;
				for (int j = 0; j < E[u].size(); ++j)
					if (abs(a.back().st) != E[u][j].st){
						a.push_back(E[u][j].nd);
						break;
					}
			}
			vis[abs(a.back().nd)] = true;

			ll s[2] = {0, 0};
			int u = abs(a[0].st), v = abs(a.back().nd);
			for (int j = 0; j < 2; ++j){
				solve(j, a, b);
				for (int k = 0; k < 2; ++k)
					for (int l = 0; l < 2; ++l)
						s[l ^ (G[u].size() ? G[u][0] < 0 ^ j : 0) ^ (G[v].size() ? G[v][0] < 0 ^ k : 0)] += b[k][l];
			}
			res.push_back(PII(s[0] % MOD, s[1] % MOD));
		}
	
	for (int i = 1; i <= m; ++i)
		if (E[i].size() == 2 && !vis[i]){
			vector<PII> a;
			a.push_back(E[i][0].nd);
			if (E[i][0].st == E[i][1].st && E[i][0].st != i){
				a.push_back(E[i][1].nd);
				swap(a.back().st, a.back().nd);
				vis[E[i][0].st] = true;
			}
			else{
				for (int u = E[i][0].st; u != i; u = abs(a.back().nd)){
					vis[u] = true;
					for (int j = 0; j < E[u].size(); ++j)
						if (abs(a.back().st) != E[u][j].st){
							a.push_back(E[u][j].nd);
							break;
						}
				}
			}

			ll s[2] = {0, 0};
			int u = abs(a[0].st), v = abs(a.back().nd);
			for (int j = 0; j < 2; ++j){
				solve(j, a, b);
				for (int l = 0; l < 2; ++l)
					s[l] += b[j][l];
			}
			res.push_back(PII(s[0] % MOD, s[1] % MOD));
		}

	ll dp[2][2] = {1, 0};
	for (int i = 0; i < res.size(); ++i){
		dp[i + 1 & 1][0] = (dp[i & 1][0] * res[i].st + dp[i & 1][1] * res[i].nd) % MOD;
		dp[i + 1 & 1][1] = (dp[i & 1][0] * res[i].nd + dp[i & 1][1] * res[i].st) % MOD;
	}
	printf("%d\n", (int)dp[res.size() & 1][1]);
	
	return 0;
}