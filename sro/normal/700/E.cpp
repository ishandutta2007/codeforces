/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

struct SAM {
	struct State {
		int to[26];
		int fa, len;
	};
	vector<State> t;
	int lst;
	void inline init() {
		t.clear(); t.pub(State()); t.pub(State());
		lst = 1; t[1].fa = t[1].len = 0;
	}
	SAM() {init();}
	int inline newnode() {
		t.pub(State());
		return SZ(t) - 1;
	}
	int inline add(int c) {
		int np = newnode(), p = lst;
		t[np].len = t[p].len + 1;
		while(p && !t[p].to[c]) {
			t[p].to[c] = np;
			p = t[p].fa;
		}
		if(!p) {
			t[np].fa = 1;
		} else {
			int q = t[p].to[c];
			if(t[p].len + 1 == t[q].len) {
				t[np].fa = q;
			} else {
				int nq = newnode();
				t[nq] = t[q];
				t[nq].len = t[p].len + 1;
				t[q].fa = t[np].fa = nq;
				while(p && t[p].to[c] == q) {
					t[p].to[c] = nq;
					p = t[p].fa;
				}
			}
		}
		return lst = np;
	}
	vector<vector<int> > getgraph() {
		vector<vector<int> > res(SZ(t));
		circ(i, 2, SZ(t) - 1) res[t[i].fa].pub(i);
		return res;
	}
} sam;

struct Node {
	int sm, mx;
	int l, r;
} t[1 << 24];

int nds = 0;
int n, m;

void inline pu(int now) {
	t[now].sm = t[t[now].l].sm + t[t[now].r].sm;
	t[now].mx = max(t[t[now].l].mx, t[t[now].r].mx);
}

void inline ins(int x, int &now, int nl = 0, int nr = n) {
	if(!now) now = ++nds;
	if(nl == nr) return (void)(t[now].sm = 1, t[now].mx = x);
	int m = (nl + nr) >> 1;
	if(m >= x) ins(x, t[now].l, nl, m);
	else ins(x, t[now].r, m + 1, nr);
	pu(now);
}

int inline qry(int l, int r, int now, int nl = 0, int nr = n) {
	if(!now || nl > r || nr < l) return 0;
	if(nl >= l && nr <= r) return t[now].sm;
	int m = (nl + nr) >> 1;
	return qry(l, r, t[now].l, nl, m) + qry(l, r, t[now].r, m + 1, nr);
}

int inline merge(int ls, int rs) {
	int ms = ++nds;
	if(!ls || !rs) return t[ms] = t[ls + rs], ms;
	t[ms].l = merge(t[ls].l, t[rs].l);
	t[ms].r = merge(t[ls].r, t[rs].r);
	return pu(ms), ms;
}

char s[1 << 18];
int pos[1 << 18], soq[1 << 19];
vector<vector<int> > nei;
int rt[1 << 19];

void dfs(int now) {
	if(~soq[now]) ins(soq[now], rt[now]);
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		dfs(to);
		rt[now] = merge(rt[now], rt[to]);
	}
}

int dp[1 << 19];
vector<int> stk;

void dft(int now) {
	dp[now] = dp[sam.t[now].fa];
	int pos = t[rt[now]].mx;
	int l = 0, r = SZ(stk);
	while(r - l > 1) {
		int m = (l + r) >> 1;
		int to = stk[m];
		int mnl = sam.t[sam.t[to].fa].len + 1;
		int Cl = pos - sam.t[now].len + mnl, Cr = pos;
		if(qry(Cl, Cr, rt[to]) >= 2) l = m;
		else r = m;
	}
	int ps = l;
	if(ps < SZ(stk)) dp[now] = max(dp[now], dp[stk[ps]] + 1);
	stk.pub(now);
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		dft(to);
	}
	stk.pob();
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	memset(soq, -1, sizeof(soq));
	sam.init(); soq[1] = 0;
	cont(i, n) pos[i] = sam.add(s[i] - 'a'), soq[pos[i]] = i;
	nei = sam.getgraph();
	m = SZ(nei) - 1;
	dfs(1); dft(1);
	int ans = 0;
	cont(i, m) ans = max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}