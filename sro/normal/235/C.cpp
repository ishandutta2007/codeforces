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
	int inline size() {return SZ(t) - 1;}
	State inline &operator[](int x) {return t[x];}
	int inline newnode() {
		t.pub(State());
		return SZ(t) - 1;
	}
	int inline add(int p, int c) {
		int np = newnode();
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
	int inline add(int c) {
		return add(lst, c);
	}
} sam;

char s[1 << 20];
int n, m, k, p;
char t[1 << 17];
vector<int> nei[1 << 21];
int cn[1 << 21];
int ep[1 << 21];

void inline dfs(int now) {
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		dfs(to);
		cn[now] += cn[to];
		ep[now] = ep[to];
	}
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	sam.init();
	cont(i, n) {
		int pos = sam.add(s[i] - 'a');
		cn[pos] = 1; ep[pos] = i;
	}
	p = SZ(sam);
	cont(i, p) nei[sam[i].fa].pub(i);
	dfs(1);
	scanf("%d", &m);
	while(m--) {
		scanf("%s", t);
		int now = 1; k = strlen(t);
		int len = 0;
		loop(i, k) {
			while(now && !sam[now].to[t[i] - 'a']) now = sam[now].fa, len = sam[now].len;
			if(!now) now = 1, len = 0;
			else now = sam[now].to[t[i] - 'a'], ++len;
		}
		set<int> lgl;
		ll ans = 0;
		loop(i, k) {
			if(i) {
				if(sam[sam[now].fa].len == k - 1) {
					now = sam[now].fa;
				}
				len = min(len, k - 1);
				while(now && !sam[now].to[t[i - 1] - 'a']) now = sam[now].fa, len = sam[now].len;
				if(!now) now = 1, len = 0;
				else now = sam[now].to[t[i - 1] - 'a'], ++len;
			}
			if(len == k) {
				if(lgl.count(now)) continue;
				lgl.insert(now);
				ans += cn[now];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}