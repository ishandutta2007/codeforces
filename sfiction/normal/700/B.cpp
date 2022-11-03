#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E5 + 10;

int n, m;
int mark[MAXN], cnt[MAXN];
vector<int> E[MAXN];

ll ans;

void DFS(int u, int pre){
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			DFS(v, u);
			cnt[u] += cnt[v];
		}
	ans += cnt[u];
}

void solve(int u, int pre){
	int s = -1;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre && (s == -1 || cnt[v] > cnt[s]))
			s = v;
	if (s != -1 && cnt[s] > m - cnt[s]){
		ans -= cnt[s];
		ans += m - cnt[s];
		solve(s, u);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	m <<= 1;
	for (int t, i = m - 1; i >= 0; --i){
		scanf("%d", &t);
		cnt[t] = mark[t] = 1;
	}
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	ans = -m;
	DFS(1, 0);
	solve(1, 0);
	printf("%I64d\n", ans);
	return 0;
}