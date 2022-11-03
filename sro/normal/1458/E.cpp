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

int n, m;
int x[1 << 17], y[1 << 17];
set<pair<int, int> > shit;
set<pair<int, int> > xs, ys;
set<pair<pair<int, int>, int> > rg;

int main() {
	scanf("%d%d", &n, &m);
	cont(i, n) {
		scanf("%d%d", x + i, y + i);
		shit.insert(mak(x[i], y[i]));
		xs.insert(mak(x[i], y[i]));
		ys.insert(mak(y[i], x[i]));
	}
	int nx = 0, ny = 0;
	while(1) {
		if(shit.count(mak(nx, ny))) {
			++nx; ++ny; continue;
		}
		while(SZ(xs) && xs.begin()->first < nx) xs.erase(xs.begin());
		while(SZ(ys) && ys.begin()->first < ny) ys.erase(ys.begin());
		if(!SZ(xs) && !SZ(ys)) break;
		pair<int, int> xi = SZ(xs) ? *xs.begin() : mak(Inf, Inf);
		pair<int, int> yi = SZ(ys) ? *ys.begin() : mak(Inf, Inf);
		swap(yi.first, yi.second);
		int len = min(xi.first - nx, yi.second - ny);
		if(len) {
			rg.insert(mak(mak(nx, ny), len - 1));
			nx += len; ny += len;
		}
		int rchx = (xi.first == nx && xi.second <= ny);
		int rchy = (yi.second == ny && yi.first <= nx);
		if(!rchx && !rchy) {
			rg.insert(mak(mak(nx, ny), 0));
			++nx, ++ny;
		}
		nx += rchx; ny += rchy;
	}
	rg.insert(mak(mak(nx, ny), Inf));
	while(m--) {
		int x, y; scanf("%d%d", &x, &y);
		if(shit.count(mak(x, y))) {
			puts("LOSE"); continue;
		}
		__typeof(rg.begin()) it = rg.upper_bound(mak(mak(x, y), Inf));
		if(it == rg.begin()) {
			puts("WIN"); continue;
		}
		--it;
		int nx = it->first.first, ny = it->first.second, len = it->second;
		if(x - nx == y - ny && x - nx <= len) puts("LOSE");
		else puts("WIN");
	}
	return 0;
}