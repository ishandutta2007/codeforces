#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int n, m, Xor;
vector<pair<int, int> > adj[MAXN];

void read() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		Xor ^= w;
	}
}

int par[MAXN], par_w[MAXN], d[MAXN];
bool visited[MAXN];
vector<vector<int> > c;

void dfs(int u, int pr) {
	visited[u] = true;
	for(auto e: adj[u]) {
		if(!visited[e.first]) {
			par[e.first] = u;
			par_w[e.first] = e.second;
			d[e.first] = 1 + d[u];
			dfs(e.first, u);
		} else if(pr != e.first && d[e.first] < d[u]) {
			int x = u;
			vector<int> cycle = {e.second};
			do {
				cycle.pb(par_w[x]);
				x = par[x];		
			} while(x != e.first);
			c.pb(cycle);
		}
	}
}

const int mod = (int)1e9 + 7;
const int inv2 = (mod + 1) / 2; 

void fft(int* a, int low, int high)
{
	if(high == low + 1)
		return;

	int len = (high - low) >> 1, mid = low + len;
	fft(a, low, mid);
	fft(a, mid, high);

	for(int i = low; i < mid; i++)
	{
		int x1 = a[i] % mod;
		int x2 = a[i + len] % mod;

		a[i] = (x1 - x2 + mod) % mod;
		a[i + len] = (x1 + x2) % mod;
	}
}

void inv_fft(int *a, int low, int high)
{
	if(high == low + 1)
		return;

	int len = (high - low) >> 1, mid = low + len;

	for(int i = low; i < mid; i++)
	{
		int y1 = a[i] % mod;
		int y2 = a[i + len] % mod;

		a[i] = ((y1 + y2) * 1ll * inv2) % mod;
		a[i + len] = ((y2 - y1 + mod) * 1ll * inv2) % mod;
	}
	
	inv_fft(a, low, mid);
	inv_fft(a, mid, high);
}

const int N = (1 << 17);
int ans[N], tmp[N];
int ok[N];

void solve() {
	dfs(1, -1);
	ans[Xor] = 1;
	ok[Xor] = 1;

	fft(ans, 0, N);

	for(int i = 0; i < SZ(c); i++) {
		memset(tmp, 0, sizeof(tmp));
		for(int v: c[i])
			++tmp[v];
		
		fft(tmp, 0, N);
		fft(ok, 0, N);
		for(int i = 0; i < N; i++) {
			ans[i] = ans[i] * 1ll * tmp[i] % mod;
			ok[i] = ok[i] * 1ll * tmp[i] % mod;
		}

		inv_fft(ok, 0, N);
		for(int i = 0; i < N; i++)
			ok[i] = ok[i] != 0;
	}

	inv_fft(ans, 0, N);

	for(int i = 0; i < N; i++) {
		if(ok[i]) {
			cout << i << " " << ans[i] << endl;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}