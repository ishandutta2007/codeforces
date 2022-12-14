#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int max0 = 153, max1 = 174;

const int maxn = 30000, maxm = 30000;

vector<int> v;

int n, Mod, m, cntv;
int a[maxn + 5];

int bel[maxn + 5];

int fib[maxn + 5];

int ans[maxm + 5];

struct data
{
	int l, r, id;

	data() { }
	data(int _l, int _r, int _id): l(_l), r(_r), id(_id) { }

	friend bool operator<(const data &x, const data &y)
	{
		if (bel[x.l] == bel[y.l]) return (bel[x.l] & 1) ? x.r > y.r : x.r < y.r;
		return x.l < y.l;
	}

};

data q[maxm + 5];

struct node
{
	node *c[2];

	int sz;
	int sum, sum0;

	node(): sz(0), sum(0), sum0(0) { memset(c, 0, sizeof c); }

	void update()
	{
		if (c[0]) sz = c[0]->sz, sum = c[0]->sum, sum0 = c[0]->sum0;
		else sz = sum = sum0 = 0;
		if (c[1])
		{
			if (!sz) sum = c[1]->sum;
			else (sum += fib[sz] * c[1]->sum0 + fib[sz - 1] * c[1]->sum) %= Mod;
			
			(sum0 += fib[sz + 1] * c[1]->sum0 + fib[sz] * c[1]->sum) %= Mod;
			sz += c[1]->sz;
		}
	}

};

const int max2 = 10000;

node *nd_pool;
int nd_res = 0;

node *newnode()
{
	if (!nd_res) nd_pool = new node[max2], nd_res = max2;
	return nd_pool + (--nd_res);
}

node *root;

int seg_x, seg_z;

void add(node *&root, int l, int r)
{
	if (!root) root = newnode();
	if (r - l <= 1)
	{
		(root->sz += seg_z) %= Mod;
		(root->sum += seg_z * v[seg_x]) %= Mod;
		(root->sum0 += seg_z * v[seg_x]) %= Mod;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(root->c[0], l, mid);
	else add(root->c[1], mid, r);
	root->update();
}

inline bool seg_add(int x, int z)
{
	seg_x = x, seg_z = z;
	add(root, 0, cntv);
	return 1;
}

int cnt[maxn + 5];

inline void add(int x) { if (!cnt[a[x]]++) seg_add(a[x], 1); }
inline void del(int x) { if (!--cnt[a[x]]) seg_add(a[x], -1); }

int main()
{
	scanf("%d%d", &n, &Mod);
	fib[0] = 0, fib[1] = 1;
	REP(i, 2, n + 1) fib[i] = (fib[i - 1] + fib[i - 2]) % Mod;
	v.clear();
	REP(i, 0, n) scanf("%d", a + i), v.pb(a[i]);
	REP(i, 0, n + 1) bel[i] = i / max0;
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	cntv = SZ(v);
	REP(i, 0, n) a[i] = lower_bound(ALL(v), a[i]) - v.begin();
	scanf("%d", &m);
	REP(i, 0, m)
	{
		int l, r;
		scanf("%d%d", &l, &r), --l;
		q[i] = data(l, r, i);
	}
	sort(q, q + m);
	root = NULL;
	int l = 0, r = 0;
	REP(i, 0, m)
	{
		while (r < q[i].r) add(r++);
		while (l > q[i].l) add(--l);
		while (r > q[i].r) del(--r);
		while (l < q[i].l) del(l++);
		ans[q[i].id] = root->sum;
	}
	REP(i, 0, m) (ans[i] += Mod) %= Mod;
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}