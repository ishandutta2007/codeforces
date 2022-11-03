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
} sam, mas;

char s[1 << 17];
int ep[1 << 18], pe[1 << 18];
vector<int> nei[1 << 18], ien[1 << 18];
int n, m;
char t[1005];

void dfs(int now) {
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		dfs(to);
		ep[now] = max(ep[now], ep[to]);
	}
}

void sfd(int now) {
	loop(i, SZ(ien[now])) {
		int to = ien[now][i];
		sfd(to);
		pe[now] = min(pe[now], pe[to]);
	}
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	sam.init(); mas.init();
	cont(i, n) ep[sam.add(s[i] - 'A')] = i;
	memset(pe, Inf, sizeof(pe));
	range(i, n, 1, -1) pe[mas.add(s[i] - 'A')] = i;
	cont(i, SZ(sam.t) - 1) nei[sam.t[i].fa].pub(i);
	cont(i, SZ(mas.t) - 1) ien[mas.t[i].fa].pub(i);
	dfs(1); sfd(1);
	int q; scanf("%d", &q);
	int ans = 0;
	while(q--) {
		scanf("%s", t + 1); m = strlen(t + 1);
		if(m == 1) continue;
		int ps = 1, sp = 1;
		int nl = 0;
		cont(i, m) {
			while(ps && !sam.t[ps].to[t[i] - 'A']) ps = sam.t[ps].fa, nl = sam.t[ps].len;
			if(!ps) ps = 1, nl = 0;
			else ps = sam.t[ps].to[t[i] - 'A'], ++nl;
		}
		int ln = 0;
		range(i, m, 1, -1) {
			while(sp && !mas.t[sp].to[t[i] - 'A']) sp = mas.t[sp].fa, ln = mas.t[sp].len;
			if(!sp) sp = 1, ln = 0;
			else sp = mas.t[sp].to[t[i] - 'A'], ++ln;
		}
		vector<int> ls;
		while(sp) ls.pub(sp), sp = mas.t[sp].fa;
		int pos = SZ(ls) - 1;
		bool can = 0;
		range(i, m, 1, -1) {
			if(min(nl, sam.t[ps].len) < i) continue;
			if(sam.t[sam.t[ps].fa].len >= i) ps = sam.t[ps].fa;
			while(~pos && min(ln, mas.t[ls[pos]].len) + i < m) --pos;
			if(!~pos) break;
			if(ep[ps] - pe[ls[pos]] + 1 >= m) can = 1;
		}
		ans += can;
	}
	printf("%d\n", ans);
	return 0;
}