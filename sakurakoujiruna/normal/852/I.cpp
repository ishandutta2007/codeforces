#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int mxn = 100006;

int n;
int a[mxn];
int c[mxn];
vi e[mxn];
int s[mxn][2];

struct {
	int s[20][mxn * 2], d[mxn], cnt;
	void dfs(int x, int p) {
		s[0][d[x] = ++cnt] = x;
		for (auto i : e[x]) if (i != p)
			dfs(i, x), s[0][++cnt] = x;
	}
	#define cmp [&](int x, int y) { return d[x] < d[y]; }
	void build() {
		fill(d, d + n + 1, 0); cnt = 0;
		dfs(1, 0);
		for (int i = 1; cnt >> i; ++i)
			for (int j = 1 << i; j <= cnt; ++j)
				s[i][j] = min(s[i - 1][j], s[i - 1][j - (1 << i - 1)], cmp);
	}
	int operator()(int x, int y) {
		int l, r; tie(l, r) = minmax(d[x], d[y]);
		int k = 31 - __builtin_clz(r + 1 - l);
		return min(s[k][l + (1 << k) - 1], s[k][r], cmp);
	}
} lca;

int w[mxn];
int d[mxn];
int p[mxn * 2];
int cnt = 0;
void dfs(int x, int p) {
	d[x] = cnt + 1;
	for (auto i : e[x]) if (i != p) {
		::p[++cnt] = i;
		dfs(i, x);
		::p[++cnt] = i;
	}
}

struct Qry {
	int l, r, o;
	int id;
	ll ans;
};

vector<Qry> qry;

ll sum = 0;

int v[mxn];
void ins(int x) {
	if (v[x] ^= 1) {
		//cout << "+" << x << endl;
		sum += s[w[x]][c[x] ^ 1];
		++s[w[x]][c[x]];
	} else {
		//cout << "-" << x << endl;
		--s[w[x]][c[x]];
		sum -= s[w[x]][c[x] ^ 1];
	}
}

void add(int x) {
	ins(p[x]);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	
	map<int,int> id;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		id[w[i]] = 0;
	}
	
	int tid = 0;
	for (auto &i : id)
		i.sec = ++tid;
	
	for (int i = 1; i <= n; ++i)
		w[i] = id[w[i]];
	
	
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	
	lca.build();
	dfs(1, 0);
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		int o = lca(x, y);
		if (d[x] > d[y]) swap(x, y);
		qry.pb({d[x], d[y] - 1, o, i});
	}
	
	sort(qry.begin(), qry.end(), [](Qry a, Qry b) {
		return a.l < b.l;
	});
	
	const int B = 350;
	int t = 0;
	for (int l = 0; l < qry.size(); l += B, t ^= 1)
		sort(qry.begin() + l, qry.begin() + min((int)qry.size(), l + B), [&](Qry a, Qry b) {
			return t ? a.r < b.r : a.r > b.r;
		});
	
	int L = 1;
	int R = 0;
	for (auto &i : qry) {
		while (L < i.l) add(L++);
		while (L > i.l) add(--L);
		while (R < i.r) add(++R);
		while (R > i.r) add(R--);
		ins(i.o);
		i.ans = sum;
		ins(i.o);
	}
	
	sort(qry.begin(), qry.end(), [](Qry a, Qry b) {
		return a.id < b.id;
	});
	
	for (auto i : qry)
		printf("%lld\n", i.ans);
	
	return 0;
}