#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;


const ll SQ = 70;
const ll MAXN = 2e5 + 5 * SQ;

struct CHT {
	const ll INF = 8e18;
	vector<pair<ll, pll>> vec; // TOF
	int ind = 0;

	inline ll isect(pll a, pll b) {
		if (a.X == b.X)
			return a.Y < b.Y ? -INF : INF;
		if (a.X > b.X) swap(a, b);
		return (a.Y - b.Y + (a.Y <= b.Y ? 0 : 1) * (b.X - a.X - 1)) / (b.X - a.X);
	}
 
	inline void add(pll line) {
		while (!vec.empty()) {
			ll x = isect(vec.back().Y, line);
			if (x <= vec.back().X) vec.pop_back();
			else {
				vec.push_back({x, line});
				return;	
			}
		}
 
		vec.push_back({-INF, line});
	}
 
	inline ll query(ll x) {
		while (ind < int(vec.size()) - 1 && x >= vec[ind + 1].X) ind++;
		pll line = vec[ind].Y;
		return line.X * x + line.Y;
	}
} cht[MAXN / SQ][2];

int lz[MAXN / SQ], P[MAXN / SQ][SQ], TB[MAXN], TA[MAXN], n, q, t, tin[MAXN], tout[MAXN], A[MAXN], B[MAXN];
pll lines[MAXN];
vector<int> adj[MAXN];

inline pll operator- (const pll& a) {
	return {-a.X, -a.Y};
}

inline void t_add(int l, int r, int x) {
	int ind = l / SQ;
	for (int i = ind * SQ; i < (ind + 1) * SQ; i++) {
		A[i] += lz[ind];
		if (i >= l && i <= r)
			A[i] += x;
		lines[i].Y = 1ll * A[i] * B[i];
	}

	lz[ind] = 0;
	cht[ind][0].vec.clear();
	cht[ind][1].vec.clear();
	cht[ind][0].ind = 0;
	cht[ind][1].ind = 0;

	for (int i = 0; i < SQ; i++)
		cht[ind][0].add(lines[P[ind][i]]);
	for (int i = SQ - 1; i >= 0; i--)
		cht[ind][1].add(-lines[P[ind][i]]);
}

inline void add(int l, int r, int x) {
	int li = l / SQ, ri = r / SQ;
	if (li == ri) {
		t_add(l, r, x);
		return;
	}

	li++;
	ri--;
	t_add(l, li * SQ - 1, x);
	t_add((ri + 1) * SQ, r, x);
	for (int i = li; i <= ri; i++)
		lz[i] += x;
}

inline ll t_query(int l, int r) {
	int ind = l / SQ;
	ll ans = 0;
	for (int i = l; i <= r; i++) {
		ans = max(ans, 1ll * (A[i] + lz[ind]) * B[i]);
		ans = max(ans, -1ll * (A[i] + lz[ind]) * B[i]);
	}

	return ans;
}

inline ll query(int l, int r) {
	int li = l / SQ, ri = r / SQ;
	ll ans = 0;
	if (li == ri) return t_query(l, r);
	
	li++;
	ri--;
	ans = max(ans, t_query(l, li * SQ - 1));
	ans = max(ans, t_query((ri + 1) * SQ, r));

	for (int i = li; i <= ri; i++) {
		ans = max(ans, cht[i][0].query(lz[i]));
		ans = max(ans, cht[i][1].query(lz[i]));
	}

	return ans;
}

inline void build(int ind) {
	int l = (SQ * ind);
	for (int i = 0; i < SQ; i++)
		P[ind][i] = i + l;

	sort(P[ind], P[ind] + SQ, [] (int i, int j) {
		return B[i] < B[j];
	});

	for (int i = 0; i < SQ; i++) {
		int x = P[ind][i];
		lines[x] = {B[x], 1ll * B[x] * A[x]};
		cht[ind][0].add(lines[x]);
	}
	for (int i = SQ - 1; i >= 0; i--)
		cht[ind][1].add(-lines[P[ind][i]]);
}

void dfs(int v) {
	tin[v] = t++;
	for (int u : adj[v]) {
		TB[u] += TB[v];
		TA[u] += TA[v];
		dfs(u);
	}

	tout[v] = t - 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}

	for (int i = 1; i <= n; i++) cin >> TA[i];
	for (int i = 1; i <= n; i++) cin >> TB[i];
	dfs(1);

	for (int i = 1; i <= n; i++) {
		A[tin[i]] = TA[i];
		B[tin[i]] = TB[i];
	}
	
	for (int i = 0; i <= n / SQ; i++)
		build(i);

	while (q--) {
		int c, v;
		cin >> c >> v;
		if (c == 1) {
			int x;
			cin >> x;
			add(tin[v], tout[v], x);
		} else {
			cout << query(tin[v], tout[v]) << endl;
		}
	}
	return 0;
}