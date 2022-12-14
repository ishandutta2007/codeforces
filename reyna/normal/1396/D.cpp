
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 6005, mod = (int) 1e9 + 7;
int len;
int seg[N << 2], mx[N << 2], sum[N << 2], ch[N<<2], px[N], py[N], pc[N], o[N], sx[N], sy[N], sc[N];
set<pair<int, int>> col[N];
vector<int> allx, ally;

int get_pos(int x) {
	return lower_bound(ALL(ally), x) - ally.begin();	
}
void build(int v = 1, int b = 0, int e = (int) ally.size()-1) {
	ch[v] = -1;
	mx[v] = 0;
	if (b + 1 == e) {
		seg[v] = (ally[e]-ally[b]) * (long long) (len - 0) % mod;
		return;	
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	seg[v] = (seg[l] + seg[r]) % mod;
}
void apply(int v, int b, int e, int x) {
	assert(mx[v] != -1);
	if (mx[v] >= x) return;
	seg[v] = (len - x) * (long long) (ally[e] - ally[b]) % mod;
	mx[v] = x;
	ch[v] = x;
	
}
void push(int v, int b, int e) {
	if (ch[v] == -1) return;
	int m = b + e >> 1, l = v << 1, r = l | 1;
	apply(l, b, m, ch[v]);
	apply(r, m, e, ch[v]);
	ch[v] = -1;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = (int) ally.size()-1) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j && mx[v] != -1) {
		apply(v, b, e, x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, b, e);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = (seg[l] + seg[r]) % mod;
	mx[v] = (mx[l] == mx[r] ? mx[l] : -1);
}
int cmp(int x, int y) { return px[x] < px[y]; }
int main() {
	int n, k;
	cin >> n >> k >> len;
	for (int i = 0; i < n; ++i) {
		cin >> px[i] >> py[i] >> pc[i];
		allx.pb(px[i]);
		ally.pb(py[i]);
		ally.pb(py[i]+1);
		o[i] = i;
		--pc[i];
	}
	o[n] = n;
	sort(o, o + n, cmp);
	allx.pb(0); allx.pb(len);
	ally.pb(0); ally.pb(len);
	sort(ALL(allx)); sort(ALL(ally));
	allx.resize(unique(ALL(allx)) - allx.begin());
	ally.resize(unique(ALL(ally)) - ally.begin());
	sx[n] = len;
	for (int i = 0; i < n; ++i) sx[i] = px[o[i]], sy[i] = py[o[i]], sc[i] = pc[o[i]];
	int res = 0;
	for (int l = 0; l < n; ++l) {
		int s = (sx[l] - (l == 0 ? -1 : sx[l-1]));
		if (!s) continue;
		for (int i = 0; i < k; ++i) {
			col[i].clear();
			col[i].insert(mp(-1, -1));
			col[i].insert(mp(len, -1));
		}
		for (int cur = l; cur < n; ++cur) {
			col[sc[cur]].insert(mp(sy[cur], cur));
		}
		build();
		for (int color = 0; color < k; ++color) {
			int lasty = -1;
			for (auto it : col[color]) {
				int cury = it.first;
				update(get_pos(lasty+1), get_pos(cury+1), cury);
			//	cout << l << " HI " << get_pos(lasty+1) << ' ' << get_pos(cury+1) << ' ' << cury << ' ' << get_pos(len) << ' ' << color  << endl;
				lasty = cury;
			}
		}
		for (int r = n; r >= l+1; --r) {
			int mult = (long long) (sx[l] - (l == 0 ? -1 : sx[l-1])) * (sx[r] - sx[r-1]) % mod;
		//	cout << " hi " << mult << ' ' << l << ' ' << r << ' ' << sx[l] << ' ' << sx[r] << ' ' << seg[1] << endl;
			res = (res + (long long) mult * seg[1]) % mod;
			int id = r-1;
			auto it = col[sc[id]].lower_bound(mp(sy[id], id));
			--it;
			col[sc[id]].erase(mp(sy[id], id));
			auto nx = it;
			++nx;
			update(get_pos((it->first)+1), get_pos((nx->first)+1), nx->first);
		}
	}
	cout << res << endl;
	
}