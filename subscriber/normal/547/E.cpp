#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 611111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

char ss[N];

int s[N];

pair<pair<int, int>, int> p[N];
int lc[21][N];
int gg[N];
int c[21][N];

int su[N];

int it, n, q;
int nn = 0;

int len[N], st[N];
int ans[N], rev[N];

int lcp(int x, int y) {
	int r = 0;
	for (int i = it; i >= 0; i--) if (x + pw(i) <= nn && y + pw(i) <= nn && c[i][x] == c[i][y]) {
		x += pw(i);
		y += pw(i);
		r += pw(i);
	}
	return r;
}

int flc(int x, int y) {
	if (x > y) return 1e9;
	int w = gg[y - x + 1];

	return min(lc[w][x], lc[w][y - pw(w) + 1]);
}

void add(int x) {
	x++;
	while (x <= n) {
		su[x]++;
		x = x + x - (x & (x - 1));
	}
}

int fin(int x) {
	int r = 0;
	x++;
	while (x > 0) {
		r += su[x];
		x &= x - 1;
	}
	return r;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d\n", &n, &q);


	for (int i = 0; i < n; i++) {
		gets(ss);
		int k = strlen(ss);

		len[i] = k;
		st[i] = nn;

		for (int j = 0; j < k; j++) s[nn++] = ss[j] - 'a';
		s[nn++] = 27 + i;
	}
	for (int i = 0; i < nn; i++) p[i] = mp(mp(s[i], 0), i);
	sort(p, p + nn);

	int e = 0;
	for (int i = 0; i < nn; i++) {
		if (i > 0 && p[i].F != p[i - 1].F) e++;
		c[0][p[i].S] = e;
	}
	it = 0;
	while (pw(it) < nn) {
		it++;
		for (int i = 0; i < nn; i++) if (i + pw(it - 1) < nn) p[i] = mp(mp(c[it - 1][i], c[it - 1][i + pw(it - 1)]), i); else
			p[i] = mp(mp(c[it - 1][i], -1), i);
		sort(p, p + nn);
		e = 0;
		for (int i = 0; i < nn; i++) {
			if (i > 0 && p[i].F != p[i - 1].F) e++;
			c[it][p[i].S] = e;
		}			
	}
	gg[1] = 0;
	for (int i = 2; i <= nn; i++) gg[i] = gg[i / 2] + 1;

	for (int i = 0; i < nn - 1; i++) lc[0][i] = lcp(p[i].S, p[i + 1].S);
	for (int i = 1; i <= gg[nn - 1]; i++) for (int j = 0; j < nn - 1; j++) if (j + pw(i) <= nn - 1) lc[i][j] = min(lc[i - 1][j], lc[i - 1][j + pw(i - 1)]);

	for (int i = 0; i < nn; i++) rev[p[i].S] = i;

	vector<pair<pair<int, int>, pair<int, int> > > ev;
	for (int i = 0; i < q; i++) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		l--;
		r--;
		k--;

		int ce = rev[st[k]];
		int q1 = ce, q2 = ce;

		int le = 0;
		int ri = ce;
		while (le < ri) {
			int mid = (le + ri) / 2;
			if (flc(mid, ce - 1) < len[k]) le = mid + 1; else ri = mid;
		}
		q1 = le;

		le = ce;
		ri = nn - 1;
		while (le < ri) {
			int mid = (le + ri + 1) / 2;
			if (flc(q1, mid - 1) < len[k]) ri = mid - 1; else le = mid;
		}
		q2 = le;

		ans[i] = 0;
		ev.pb(mp(mp(q2, 2), mp(r, i)));
		ev.pb(mp(mp(q2, 1), mp(l - 1, i)));

		ev.pb(mp(mp(q1 - 1, 1), mp(r, i)));
		ev.pb(mp(mp(q1 - 1, 2), mp(l - 1, i)));
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < len[i]; j++) ev.pb(mp(mp(rev[st[i] + j], 0), mp(i, -1)));
	sort(ev.begin(), ev.end());
	for (int i = 0; i < ev.size(); i++) {
		if (ev[i].F.S == 0) {
			add(ev[i].S.F);
		} else {
			int coef = 1;
			if (ev[i].F.S == 1) coef = -1;
			ans[ev[i].S.S] += coef * fin(ev[i].S.F);
		}
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);

	return 0;
}