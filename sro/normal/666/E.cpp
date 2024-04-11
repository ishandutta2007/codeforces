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

int n;
int ls[1 << 24], rs[1 << 24], nds;
pair<int, int> dt[1 << 24];

void inline pu(int now) {
	dt[now] = max(dt[ls[now]], dt[rs[now]]);
}

void inline add(int to, int &now, int nl = 1, int nr = n) {
	if(!now) now = ++nds;
	if(nl == nr) return (void)(++dt[now].first, dt[now].second = -to);
	int m = (nl + nr) >> 1;
	if(m >= to) add(to, ls[now], nl, m);
	else add(to, rs[now], m + 1, nr);
	pu(now);
}

int inline merge(int a, int b, int nl = 1, int nr = n) {
	if(!a || !b) return a + b;
	int c = ++nds;
	if(nl == nr) {
		dt[c] = dt[a];
		dt[c].first += dt[b].first;
		return c;
	}
	int m = (nl + nr) >> 1;
	ls[c] = merge(ls[a], ls[b], nl, m);
	rs[c] = merge(rs[a], rs[b], m + 1, nr);
	pu(c); return c;
}

pair<int, int> inline get(int l, int r, int now, int nl = 1, int nr = n) {
	if(!now || nl > r || nr < l) return mak(0, 0);
	if(nl >= l && nr <= r) return dt[now];
	int m = (nl + nr) >> 1;
	return max(
		get(l, r, ls[now], nl, m),
		get(l, r, rs[now], m + 1, nr)
	);
}

int nxt[1 << 17][26], Fa[18][1 << 17], len[1 << 17], ts = 1;
int *fa = Fa[0];
int rt[1 << 17];

int inline append(int p, int ch) {
	int np = ++ts; len[np] = len[p] + 1;
	while(p && !nxt[p][ch]) {
		nxt[p][ch] = np;
		p = fa[p];
	}
	if(!p) {
		fa[np] = 1;
	} else {
		int q = nxt[p][ch];
		if(len[q] == len[p] + 1) {
			fa[np] = q;
		} else {
			int nq = ++ts;
			memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
			fa[nq] = fa[q]; fa[q] = fa[np] = nq;
			len[nq] = len[p] + 1;
			while(p && nxt[p][ch] == q) {
				nxt[p][ch] = nq;
				p = fa[p];
			}
		}
	}
	return np;
}

char s[1 << 19];
int m;
char tmp[1 << 19];
vector<int> nei[1 << 17];
int pos[1 << 19], pl[1 << 19];

void inline dfs(int now) {
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		dfs(to);
		rt[now] = merge(rt[now], rt[to]);
	}
}

int main() {
	scanf("%s", s + 1); m = strlen(s + 1);
	scanf("%d", &n);
	cont(i, n) {
		scanf("%s", tmp);
		int now = 1;
		for(int j = 0; tmp[j]; ++j) {
			now = append(now, tmp[j] - 'a');
			add(i, rt[now]);
		}
	}
	cont(i, ts) nei[fa[i]].pub(i);
	dfs(1);
	loop(i, 17) cont(j, ts) Fa[i + 1][j] = Fa[i][Fa[i][j]];
	int now = 1, ln = 0;
	cont(i, m) {
		int ch = s[i] - 'a';
		if(nxt[now][ch]) {
			now = nxt[now][ch]; ++ln;
		} else {
			while(now && !nxt[now][ch]) now = fa[now];
			if(now) ln = len[now] + 1, now = nxt[now][ch];
			else ln = 0, now = 1;
		}
		pos[i] = now; pl[i] = ln;
	}
	int q; scanf("%d", &q);
	while(q--) {
		int l, r, sl, sr, ss;
		scanf("%d%d%d%d", &l, &r, &sl, &sr);
		ss = sr - sl + 1;
		if(ss > pl[sr]) {
			printf("%d 0\n", l);
			continue;
		}
		int now = pos[sr];
		range(i, 17, 0, -1) if(len[Fa[i][now]] >= ss) now = Fa[i][now];
		pair<int, int> res = get(l, r, rt[now]);
		if(!res.first) res.second = -l;
		printf("%d %d\n", -res.second, res.first);
	}
	return 0;
}