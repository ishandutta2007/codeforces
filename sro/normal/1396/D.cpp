/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
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

const int jt = 1000000007;
int n, k, L;
int xs, ys;
vector<int> xls, yls, yis[2233];
multiset<int> cls[2233];
int in[2233], dis[2233];
int x[2233], y[2233], c[2233];
vector<pair<int, int> > nds[2233];
int nxt[2233];

struct Segtree {
	int st[8410], nd[8410], tag[8410];
	ll res[8410], sm[8410];
	void inline pu(int now) {
		if(st[now << 1] < st[now << 1 | 1]) {
			st[now] = st[now << 1];
			sm[now] = sm[now << 1];
			nd[now] = min(nd[now << 1], st[now << 1 | 1]);
		} else if(st[now << 1] > st[now << 1 | 1]) {
			st[now] = st[now << 1 | 1];
			sm[now] = sm[now << 1 | 1];
			nd[now] = min(st[now << 1], nd[now << 1 | 1]);
		} else {
			st[now] = st[now << 1];
			sm[now] = sm[now << 1] + sm[now << 1 | 1];
			nd[now] = min(nd[now << 1], nd[now << 1 | 1]);
		}
		res[now] = res[now << 1] + res[now << 1 | 1];
	}
	void inline beat(int now, int x) {
		if(x <= st[now]) return;
		if(x < nd[now]) {
			tag[now] = max(tag[now], x);
			res[now] += 1ll * (x - st[now]) * sm[now];
			st[now] = x;
			return;
		}
		beat(now << 1, x);
		beat(now << 1 | 1, x);
		pu(now);
	}
	void inline pd(int now) {
		beat(now << 1, tag[now]);
		beat(now << 1 | 1, tag[now]);
	}
	void inline init(int now = 1, int nl = 0, int nr = ys - 1) {
		tag[now] = -Inf;
		if(nl == nr) {
			st[now] = in[nl]; nd[now] = Inf;
			sm[now] = dis[nl]; res[now] = 1ll * dis[nl] * in[nl];
			return;
		}
		int m = (nl + nr) >> 1;
		init(now << 1, nl, m);
		init(now << 1 | 1, m + 1, nr);
		pu(now);
	}
	void inline change(int l, int r, int x, int now = 1, int nl = 0, int nr = ys - 1) {
		if(nl > r || nr < l) return;
		if(nl >= l && nr <= r) return beat(now, x);
		pd(now); int m = (nl + nr) >> 1;
		change(l, r, x, now << 1, nl, m);
		change(l, r, x, now << 1 | 1, m + 1, nr);
		pu(now);
	}
}seg;

int main() {
	scanf("%d%d%d", &n, &k, &L);
	cont(i, n) {
		scanf("%d%d%d", x + i, y + i, c + i);
		x[i]++; y[i]++;
		xls.pub(x[i]); yls.pub(y[i]);
	}
	sort(all(xls)); xls.resize(unique(all(xls)) - xls.begin()); xs = SZ(xls);
	sort(all(yls)); yls.resize(unique(all(yls)) - yls.begin()); ys = SZ(yls);
	cont(i, n) {
		x[i] = lower_bound(all(xls), x[i]) - xls.begin();
		y[i] = lower_bound(all(yls), y[i]) - yls.begin();
		nds[x[i]].pub(mak(y[i], c[i]));
	}
	loop(i, ys) dis[i] = yls[i] - (i ? yls[i - 1] : 0);
	int ans = 0;
	loop(i, xs) {
		loop(j, ys) yis[j].clear();
		loop(j, i + 1) {
			loop(k, SZ(nds[j])) {
				int y = nds[j][k].first, c = nds[j][k].second;
				cls[c].insert(y);
				yis[y].pub(c);
			}
		}
		multiset<int> nxts;
		cont(j, k) {
			nxt[j] = L + 1;
			nxts.insert(-(L + 1));
		}
		range(j, ys - 1, 0, -1) {
			loop(k, SZ(yis[j])) {
				nxts.erase(nxts.find(-nxt[yis[j][k]]));
				nxt[yis[j][k]] = j;
				nxts.insert(-nxt[yis[j][k]]);
			}
			in[j] = -*nxts.begin();
			if(in[j] != L + 1) in[j] = yls[in[j]];
		}
		seg.init();
		int xr = (i == xs - 1 ? L + 1 - xls[i] : xls[i + 1] - xls[i]);
		loop(j, i + 1) {
			int allen = 1ll * xr * (xls[j] - (j ? xls[j - 1] : 0)) % jt;
			ans = (ans + (1ll * yls.back() * (L + 1) - seg.res[1]) % jt * allen) % jt;
			loop(k, SZ(nds[j])) {
				int y = nds[j][k].first, c = nds[j][k].second;
				cls[c].erase(cls[c].find(y));
				if(!cls[c].count(y)) {
					multiset<int>::iterator it = cls[c].lower_bound(y);
					int nxt = (it == cls[c].end() ? L + 1 : yls[*it]);
					if(it == cls[c].begin()) seg.change(0, y, nxt);
					else seg.change(*(--it) + 1, y, nxt);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}