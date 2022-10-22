#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int sz = 1 << 18;

struct segtree {
	vector<vector<ll> > dat;
	segtree(){}

	void init(vector<ll> num)
	{
		dat.resize(sz * 2);

		rep(i, sz * 2) {
			dat[i].clear();
		}

		rep(i, num.size()) {
			dat[sz - 1 + i].pb(num[i]);
		}

		for (int i = sz - 2; i >= 0; --i) {
			int lc = i * 2 + 1, rc = i * 2 + 2;
			dat[i].resize(dat[lc].size() + dat[rc].size());
			merge(dat[lc].begin(), dat[lc].end(), dat[rc].begin(), dat[rc].end(), dat[i].begin());
		}
	}

	int ask(int a, int b, ll t, int k = 0, int l = 0, int r = sz)
	{
		if (b <= l || r <= a) return 0;
		if (a <= l && r <= b) {
			return upper_bound(ALL(dat[k]), t) - dat[k].begin();
		}

		return ask(a, b, t, k * 2 + 1, l, (l + r) / 2) + ask(a, b, t, k * 2 + 2, (l + r) / 2, r);
	}
} seg;

int n;
ll a[200010];
ll dep[200010];
vector<pair<int,ll>> g[200010];
int in[200010];
int out[200010];

void dfs(int v, int p, ll d, int &k) {
	dep[v] = d;
	in[v] = k++;

	for (auto e : g[v]) if (e.fi != p) {
		dfs(e.fi, v, d + e.se, k);
	}

	out[v] = k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n-1) {
		int a; ll b;
		cin >> a >> b;
		--a;
		g[i+1].eb(a, b);
		g[a].eb(i+1, b);
	}

	int now = 0;
	dfs(0, -1, 0, now);
	vector<ll> vec(n);

	rep(i, n) {
		vec[in[i]] = dep[i] - a[i];
	}

	seg.init(vec);

	rep(i, n) {
		int num = seg.ask(in[i], out[i], dep[i]) - 1;
		cout << num << (i == n - 1 ? '\n' : ' ');
	}
	
	return 0;
}