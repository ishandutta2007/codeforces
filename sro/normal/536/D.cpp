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

template<typename num> struct Lissan {
	vector<num> lss; bool built;
	num inline operator[](int id) {return lss[id];}
	void inline clear() {lss.clear(); built = 0;}
	void inline add(num x) {lss.pub(x);}
	void inline build() {sort(all(lss)); lss.erase(unique(all(lss)), lss.end()); built = 1;}
	int inline size() {assert(built); return SZ(lss);} // Don't forget to build before querying.
	int inline operator()(num x, int th = 0) {assert(built); return lower_bound(all(lss), x) - lss.begin() + th;}
};

int n, m, s, t;
int p[2005];
vector<pair<int, int> > nei[2005];
ll dis[2][2005];
Lissan<ll> lss;

void inline dijk(int fr, int id) {
	priority_queue<pair<ll, int> > pq;
	memset(dis[id], Inf, sizeof(dis[id]));
	pq.push(mak(0, fr)); dis[id][fr] = 0;
	while(SZ(pq)) {
		pair<ll, int> P = pq.top(); pq.pop();
		ll dist = -P.first, x = P.second;
		if(dis[id][x] != dist) continue;
		loop(i, SZ(nei[x])) {
			int to = nei[x][i].first, cst = nei[x][i].second;
			if(dis[id][to] > dist + cst) {
				dis[id][to] = dist + cst;
				pq.push(mak(-dis[id][to], to));
			}
		}
	}
	lss.clear();
	cont(i, n) lss.add(dis[id][i]);
	lss.build();
	cont(i, n) dis[id][i] = lss(dis[id][i], 1);
}

ll cnt[2005][2005];
ll sum[2005][2005];
ll f[2][2005][2005];

ll get(ll a[][2005], int x1, int y1, int x2, int y2) {
	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	cont(i, n) scanf("%d", p + i);
	cont(i, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		nei[a].pub(mak(b, c));
		nei[b].pub(mak(a, c));
	}
	dijk(s, 0); dijk(t, 1);
	cont(i, n) {
		++cnt[dis[0][i]][dis[1][i]];
		sum[dis[0][i]][dis[1][i]] += p[i];
	}
	cont(i, n) cont(j, n) {
		cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
		sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	}
	range(i, n, 1, -1) range(j, n, 1, -1) {
		if(get(cnt, i, j, i, n)) f[0][i][j] = max(f[0][i + 1][j], f[1][i + 1][j]) + get(sum, i, j, i, n);
		else f[0][i][j] = f[0][i + 1][j];
		if(get(cnt, i, j, n, j)) f[1][i][j] = min(f[1][i][j + 1], f[0][i][j + 1]) - get(sum, i, j, n, j);
		else f[1][i][j] = f[1][i][j + 1];
	}
	if(f[0][1][1] < 0) puts("Cry");
	else if(f[0][1][1]) puts("Break a heart");
	else puts("Flowers");
	return 0;
}