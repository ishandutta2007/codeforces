#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

int m;

map<pii, int> num;
int u[100010], v[100010];
ld x[100010], y[100010];
vector<int> e[100010];
vector<int> tol[100010];

ld Y_NOW = 0;

ld calc(int a) {
	return (x[u[a]] * (y[v[a]] - Y_NOW) + x[v[a]] * (Y_NOW - y[u[a]])) / (y[v[a]] - y[u[a]]);
}

struct cmp {
	bool operator()(int a, int b) const {
		return calc(a) < calc(b);
	}
};

vector<int> sorted;
int nis[100010];
bool used[100010];

void dfstol(int qwe) {
	if (used[qwe]) {
		return;
	}
	used[qwe] = 1;
	forn (i, tol[qwe].size()) {
		dfstol(tol[qwe][i]);
	}
	sorted.pb(qwe);
}

int tree_size = 1;

int tree[1010000];
int lb[1010000], rb[1010000];

void add(int x) {
	x += tree_size;
	while (x) {
		tree[x]++;
		x >>= 1;
	}
}

int sum(int l, int r, int x = 1) {
	if (rb[x] < l || lb[x] > r) {
		return 0;
	}
	if (lb[x] >= l && rb[x] <= r) {
		return tree[x];
	}
	return sum(l, r, x * 2) + sum(l, r, x * 2 + 1);
}

bool vused[100010];

int numbyy[100010];
int lsum[100010];

int cyc[1000010];
int en[1000010];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n, m;
	cin >> n >> m;
	forn (i, m) {
		scanf("%d%d", &u[i], &v[i]);
		u[i]--;
		v[i]--;
		num[mp(u[i], v[i])] = i;
		num[mp(v[i], u[i])] = i;
		e[u[i]].pb(i);
		e[v[i]].pb(i);
	}
	vector<pair<ld, int> > w;
	forn (i, n) {
		int x1, y1;
		scanf("%d%d", &x1, &y1);
		x[i] = cosl(1) * x1 + sinl(1) * y1;
		y[i] = cosl(1) * y1 - sinl(1) * x1;
		w.pb(mp(y[i], i));
	}
	forn (i, m) {
		if (y[u[i]] > y[v[i]]) {
			swap(u[i], v[i]);
		}
	}
	sort(w.begin(), w.end());
	forn (i, w.size()) {
		numbyy[w[i].sc] = i;
	}
	set<int, cmp> ixy;
	forn (wi, w.size() - 1) {
		int i = w[wi].sc;
		forn (j, e[i].size()) {
			int k = e[i][j];
			if (v[k] == i) {
				ixy.erase(k);
			}
		}
		Y_NOW = (w[wi].fs + w[wi + 1].fs) / 2;
		forn (j, e[i].size()) {
			int k = e[i][j];
			if (u[k] == i) {
				set<int>::iterator iter = ixy.insert(k).fs, iter1 = iter;
				if (iter != ixy.begin()) {
					iter--;
					tol[k].pb(*iter);
				}
				iter1++;
				if (iter1 != ixy.end()) {
					tol[*iter1].pb(k);
				}
			}
		}
	}
	memset(used, 0, sizeof used);
	forn (i, m) {
		dfstol(i);
	}
	while (tree_size < n) {
		tree_size *= 2;
	}
	ford (i, tree_size * 2) {
		if (i >= tree_size) {
			lb[i] = rb[i] = i - tree_size;
		} else {
			lb[i] = lb[2 * i];
			rb[i] = rb[2 * i + 1];
		}
		tree[i] = 0;
	}
	memset(vused, 0, sizeof vused);
	forn (ii, m) {
		int i = sorted[ii];
		if (!vused[u[i]]) {
			add(numbyy[u[i]]);
			vused[u[i]] = 1;
		}
		if (!vused[v[i]]) {
			add(numbyy[v[i]]);
			vused[v[i]] = 1;
		}
		lsum[i] = sum(numbyy[u[i]], numbyy[v[i]]);
	}
	int Q;
	cin >> Q;
	forn (i, m) {
		nis[sorted[i]] = i;
	}
	forn (trk, Q) {
		int k;
		scanf("%d", &k);
		forn (i, k) {
			scanf("%d", &cyc[i]);
			cyc[i]--;
		}
		cyc[k] = cyc[0];
		ld s = 0;
		forn (i, k) {
			s += ld((x[cyc[i + 1]] + x[cyc[i]]) * (y[cyc[i + 1]] - y[cyc[i]]));
		}
		if (s < 0) {
			reverse(cyc, cyc + k + 1);
		}
		ll ans = 0;
		cyc[k + 1] = cyc[1];
		forn (i, k + 1) {
			en[i] = num[mp(cyc[i], cyc[i + 1])];
		}
		forn (i, k) {
			if (y[cyc[i + 1]] > y[cyc[i]]) {
				ans += lsum[en[i]];
			} else {
				ans -= lsum[en[i]];
			}
		}
		forn (i, k) {
			if (y[cyc[i]] < y[cyc[i + 1]]) {
				if (y[cyc[i + 1]] < y[cyc[i + 2]]) {
					ans--;
				} else {
					if (nis[en[i]] < nis[en[i + 1]]) {
					} else {
						ans++;
					}
				}
			} else {
				if (y[cyc[i + 1]] < y[cyc[i + 2]]) {
					if (nis[en[i]] < nis[en[i + 1]]) {
						ans++;
					} else {
					}
				} else {
					ans += 2;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}