#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 200010;

int N;
vector<int> G[maxn], rG[maxn];
vector<int> vs; 

bool vis[maxn];
bool ng[maxn];
int cmp[maxn];

void add_edge(int from, int to) {
	G[from].pb(to);
	rG[to].pb(from);
}

void dfs(int v) {
	vis[v] = true;

	for (int to : G[v]) {
		if (!vis[to]) {
			dfs(to);
		}
	}

	vs.push_back(v);
}

void rdfs(int v, int k) {
	vis[v] = true;
	cmp[v] = k;
	for (int to : rG[v]) {
		if (!vis[to]) {
			rdfs(to, k);
		}
	}
}

int scc() {
	memset(vis, 0, sizeof(vis));
	vs.clear();

	rep(v, N) if (!vis[v]) dfs(v);

	memset(vis, 0, sizeof(vis));

	int k = 0;
	reverse(ALL(vs));

	for (int v : vs) {
		if (!vis[v]) {
			rdfs(v, k++);
		}
	}

	return k;
}

struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
	if (b == 0) {
		if (a >= 0) return EG{a, 1, 0};
		else return EG{-a, -1, 0};
	} else {
		auto e = ext_gcd(b, a % b);
		return EG{e.g, e.y, e.x - a / b * e.y};
	}
}
ll inv_mod(ll x, ll md) {
	auto z = ext_gcd(x, md).x;
	return (z % md + md) % md;
}

V<int> vals[maxn];
int dp[maxn], pre[maxn];

int main() {
	int n, m; cin >> n >> m;
	rep(i, n) {
		int x; cin >> x;
		ng[x] = 1;
		if (x == 0) {
			ng[m] = 1;
		}
	}

	for (int i = 1; i <= m; ++i) {
		int v = __gcd(m, i);
		if (!ng[i]) {
			vals[v].pb(i);
		}

		for (int j = i * 2; j <= m; j += i) {
			add_edge(i, j);
		}
	}

	N = m + 1;
	int now = scc();

	memset(pre, -1, sizeof(pre));

	V<int> used(now);

	for (int i = 1; i <= m; ++i) {
		int v = __gcd(m, i);
		if (!used[v]) {
			used[v] = 1;
			for (int to : rG[v]) {
				if (dp[v] < dp[to]) {
					dp[v] = dp[to];
					pre[v] = to;
				}
			}
			dp[v] += vals[v].size();
		}
	}

	for (int i = 1; i <= m; ++i) {
		dump(mp(i, dp[i]));
	}

	int mx = -1, p = -1;
	for (int i = 1; i <= m; ++i) {
		if (dp[i] > mx) {
			mx = dp[i];
			p = i;
		}
	}
	printf("%d\n", mx);
	V<int> vec;
	while (true) {
		for (int x : vals[p]) {
			vec.pb(x);
		}
		p = pre[p];
		if (p == -1) {
			break;
		}
	} 
	reverse(ALL(vec));

	auto calc = [&](int p, int q) { //p * x = q mod m
		int M = m;
		int d = __gcd(p, m);
		p /= d; M /= d; q /= d;
		int res = (ll)(ext_gcd(p, M).x + M) * q % M;
		return res;
	};

	dump(vec);

	rep(i, mx) {
		int x;
		if (i == 0) {
			x = vec[0];
		} else {
			x = calc(vec[i-1], vec[i]);
		}
		printf("%d%c", x % m, i == mx - 1 ? '\n' : ' ');
	}

	return 0;
}