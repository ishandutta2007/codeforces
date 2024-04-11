#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, ll> PIL;

const int MAXN = 1E5 + 10, MAXD = 60;
const ll MOD = 1E9 + 7;

int n, m;
vector<PIL> E[MAXN];
ll f[MAXN][MAXD][2];
ll cnt[MAXD][2];

vector<ll> a;
ll val[MAXN];
bool vis[MAXN];

void DFS(int u, int pre){
	vis[u] = true;
	for (int i = MAXD - 1; i >= 0; --i)
		f[u][i][0] = 1, f[u][i][1] = 0;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i].st) == pre)
			continue;
		if (vis[v])
			a.push_back(val[u] ^ val[v] ^ E[u][i].nd);
		else{
			val[v] = val[u] ^ E[u][i].nd;
			DFS(v, u);
			for (int j = MAXD - 1; j >= 0; --j){
				int d = E[u][i].nd >> j & 1;
				cnt[j][0] += f[u][j][0] * f[v][j][d] + f[u][j][1] * f[v][j][!d];
				cnt[j][1] += f[u][j][0] * f[v][j][!d] + f[u][j][1] * f[v][j][d];
				f[u][j][0] += f[v][j][d];
				f[u][j][1] += f[v][j][!d];
			}
		}
	}
}

PIL solve(vector<ll> &a){
	PIL ret(0, 0);
	for (int j = 0, i = MAXD - 1; i >= 0; --i){
		for (j = ret.st; j < a.size() && !(a[j] >> i & 1); ++j);
		if (j == a.size())
			continue;
		ret.nd |= a[j];
		swap(a[ret.st], a[j]);
		for (j = ret.st + 1; j < a.size(); ++j)
			if (a[j] >> i & 1)
				a[j] ^= a[ret.st];
		++ret.st;
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		E[u].push_back(PIL(v, w));
		E[v].push_back(PIL(u, w));
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!vis[i]){
			a.clear();
			memset(cnt, 0, sizeof cnt);
			DFS(i, 0);
			PIL res = solve(a);

			ll e = 1, s0 = (1ll << res.st) % MOD, s1 = (1ll << res.st >> 1) % MOD;
			for (int j = 0; j < MAXD; ++j, e = e * 2 % MOD){
				cnt[j][0] %= MOD, cnt[j][1] %= MOD;
				if (res.nd >> j & 1)
					ans += (s1 * cnt[j][0] + (s0 - s1 + MOD) * cnt[j][1]) % MOD * e % MOD;
				else
					ans += s0 * cnt[j][1] % MOD * e % MOD;
			}
			ans %= MOD;
		}
	printf("%d\n", (int)ans);
	return 0;
}