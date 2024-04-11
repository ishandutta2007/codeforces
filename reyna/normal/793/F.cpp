// In the name of God

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

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e5 + 505, sq = 350, mod = (int) 0;
int res[N], o[N], ql[N], qr[N], askx[N], asky[N], to_see[N], par[sq + 10][N], cnt[sq + 10], val[sq + 10][N];
vector<int> sizes[sq + 10], ind[sq + 10];
int find(int v, int par[N]) {
	return v == par[v] ? v : par[v] = find(par[v], par);
}
int by_y(int x, int y) { return asky[x] < asky[y]; }
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	memset(to_see, -1, sizeof to_see);
	for (int j = 0; j < m; ++j) {
		cin >> ql[j] >> qr[j];
		--ql[j], --qr[j];
		to_see[qr[j]] = j;
	}
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		cin >> askx[j] >> asky[j];
		--askx[j];
		--asky[j];
		o[j] = j;
	}
	for (int j = 0; j < sq; ++j) {
		cnt[j] = sq + 1;
	}
	sort(o, o + q, by_y);
	int pt = 0;
	for (int j = 0; j < n; ++j) {
		int id = j - j / sq * sq;
		val[j / sq][id] = j;
		par[j / sq][id] = id;
		sizes[j / sq].push_back(j);
		ind[j / sq].push_back(id);
		if (to_see[j] != -1) {
			int l = ql[to_see[j]];
			for (int g = 0; g < l / sq; ++g) {
	//			cout << " hi " << j << ' ' << g << ' ' << l << ' ' << l / sq << endl;
				while (sizes[g].size() && sizes[g].back() >= l) {
					par[g][ind[g].back()] = cnt[g];
					sizes[g].pop_back();
					ind[g].pop_back();
				}
				val[g][cnt[g]] = j;
				sizes[g].push_back(j);
				par[g][cnt[g]] = cnt[g];
				ind[g].push_back(cnt[g]);
				++cnt[g];
			}
			for (int x = l / sq * sq; x <= l; ++x) {
				int g = l / sq;
				if (val[g][find(x - x / sq * sq, par[g])] >= l) {
					par[g][x - x / sq * sq] = cnt[g];
				}
			}
			int g = l / sq;
			val[g][cnt[g]] = j;
			par[g][cnt[g]] = cnt[g];
			sizes[g].push_back(j);
			ind[g].push_back(cnt[g]);
			++cnt[g];
		}
		while (pt < q && asky[o[pt]] == j) {
			int i = askx[o[pt]], id = o[pt];
//			cout << " hi " << i << ' ' << id << ' ' << find(i - i / sq * sq, par[i / sq]) << endl;
			res[id] = val[i / sq][find(i - i / sq * sq, par[i / sq])] + 1;
			++pt;
		}
	}
	for (int j = 0; j < q; ++j)
		cout << res[j] << '\n';
}