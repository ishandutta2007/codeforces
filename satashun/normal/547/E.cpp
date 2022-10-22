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

int sz;
struct segtree {
    vector<int> dat;

    void init(int n_) {
	sz = 1;
	while (sz < n_) sz *= 2;
	dat.resize(sz * 2);
	rep(i, sz * 2) dat[i] = 114514;
    }

    void update(int pos, int x) {
	pos += sz - 1;
	dat[pos] = x;

	while (pos) {
	    pos = (pos - 1) / 2;
	    dat[pos] = min(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = sz) {
	if (b <= l || r <= a) return 114514;
	if (a <= l && r <= b) return dat[k];
	return min(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

namespace suffix_array {
#define MX 400010
    int n, k;
    int rank[MX + 1];
    int tmp[MX + 1];

    bool comp_sa(int i, int j)
    {
	if (rank[i] != rank[j]) return rank[i] < rank[j];
	else {
	    int ri = i + k <= n ? rank[i+k] : -1;
	    int rj = j + k <= n ? rank[j+k] : -1;
	    return ri < rj;
	}
    }

    void construct_sa(string S, int *sa)
    {
	n = S.size();

	for (int i = 0; i <= n; ++i) {
	    sa[i] = i;
	    rank[i] = i < n ? S[i] : -1;
	}

	for (k = 1; k <= n; k *= 2) {
	    sort(sa, sa + n + 1, comp_sa);

	    tmp[sa[0]] = 0;
	    for (int i = 1; i <= n; ++i) {
		tmp[sa[i]] = tmp[sa[i-1]] + comp_sa(sa[i-1], sa[i]);
	    }

	    for (int i = 0; i <= n; ++i)
		rank[i] = tmp[i];
	}
    }

    void construct_lcp(string S, int *sa, int *lcp)
    {
	n = S.size();
	for (int i = 0; i <= n; ++i) rank[sa[i]] = i;

	int h = 0;
	lcp[0] = 0;
	rep(i, n) {
	    int j = sa[rank[i]-1];
	    if (h) --h;

	    for (; j + h < n && i + h < n; ++h)
		if (S[j+h] != S[i+h]) break;
	    lcp[rank[i]-1] = h;
	}
    }
}

template<class T>
class BIT {
    T bit[400010];
    int n;

    public:
    BIT() {
	n = 400010;
	memset(bit, 0, sizeof(bit));
    }

    T sum(int i) {
	T s = 0;
	while (i > 0) {
	    s += bit[i];
	    i -= i & -i;
	}
	return s;
    }

    void add(int i, T x) {
	while (i <= n) {
	    bit[i] += x;
	    i += i & -i;
	}
    }
};

using namespace suffix_array;

struct ev {
    int num, tp, id;
    ev(){}
    ev(int num, int tp, int id) : num(num), tp(tp), id(id){}
    bool operator<(const ev &a) const {
	return num < a.num;
    }
};

segtree seg;
string s;
BIT<int> T;

int N, q;
int len[MX], x[MX];
int sa[MX], lcp[MX], gr[MX];
int np[MX];
pii ivl[MX];
ll ans[500010];
vector<ev> vec;
int ps[500010];
pii gs[MX];
char inn[200010];

int main() {
    scanf("%d%d", &N, &q);
    rep(i, N) {
	scanf("%s", inn);
	string in = inn;
	s += in;
	len[i] = in.size();
	if (i < N-1) s += '$';
    }

    int pos = 0;
    rep(i, N) {
	x[i] = pos;
	for (int j = pos; j < pos + len[i]; ++j) gr[j] = i;
	pos += len[i];
	gr[pos++] = -1;
    }
    rep(i, s.size()+1) gs[i] = mp(gr[i], i);
    sort(gs, gs + s.size() + 1);

    construct_sa(s, sa);
    construct_lcp(s, sa, lcp);

    rep(i, s.size()+1) np[sa[i]] = i;
    seg.init(s.size());

    rep(i, s.size()) seg.update(i, lcp[i]);

    rep(ii, N) {
	int i = np[x[ii]];
	int left, right;
	int lb, ub;

	if (lcp[i] < len[ii]) right = i;
	else if (seg.get(i, s.size()) >= len[ii]) right = s.size();
	else {
	    lb = i+1, ub = s.size();
	    while (ub - lb > 1) {
		int m = (ub + lb) / 2;
		int f = seg.get(i, m);
		if (f >= len[ii]) lb = m;
		else ub = m;
	    }
	    right = lb;
	}

	if (!i || (lcp[i-1] < len[ii])) left = i;
	else {
	    if (seg.get(0, i) >= len[ii]) left = 0;
	    else {
		lb = 0, ub = i;
		while (ub - lb > 1) {
		    int m = (ub + lb) / 2;
		    int f = seg.get(m, i);
		    if (f >= len[ii]) ub = m;
		    else lb = m;
		}
		left = ub;
	    }
	}
	ivl[ii] = mp(left, right);
    }

    rep(i, q) {
	int l, r, k;
	scanf("%d%d%d", &l, &r, &k);
	--l; --r;
	if (l) vec.eb(l-1, -1, i);
	vec.eb(r, 1, i);
	ps[i] = k-1;
    }
    sort(ALL(vec));

    int p = 0;
    for (ev &e : vec) {
	int u = e.num;
	while (p <= s.size() && gs[p].fi <= u)
	    T.add(np[gs[p++].se]+1, 1);
	ans[e.id] += (T.sum(ivl[ps[e.id]].se + 1)  - T.sum(ivl[ps[e.id]].fi)) * e.tp;
    }

    rep(i, q) printf("%d\n", ans[i]);

    return 0;
}