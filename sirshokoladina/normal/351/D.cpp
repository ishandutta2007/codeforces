#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const int N = 1 << 17;

int l[2 * N], r[2 * N], t[2 * N];

void upd (int x, int d) {
	int v = x + N - 1;
	while (1) {
		t[v] += d;
		if (!v) {
			return;
		}
		v--;
		v >>= 1;
	}
}

int get (int lb, int rb, int v = 0) {
	if (lb >= r[v] || rb <= l[v]) {
		return 0;
	}
	if (lb <= l[v] && rb >= r[v]) {
		return t[v];
	}
	return get(lb, rb, 2 * v + 1) + get(lb, rb, 2 * v + 2);
}

int n;

vector<int> occ (vector<pair<pair<int, int>, int> > a, vector<pair<int, int> > b) {
	memset(t, 0, sizeof t);
	forn (i, N) {
		l[i + N - 1] = i;
		r[i + N - 1] = i + 1;
	}
	ford (i, N - 1) {
		l[i] = l[2 * i + 1];
		r[i] = r[2 * i + 2];
	}
	vector<vector<pair<int, int> > > rotl(n + 1);
	forn (i, a.size()) {
		rotl[a[i].fs.fs].pb(mp(a[i].fs.sc, a[i].sc));
	}
	vector<vector<int> > notl(n + 1);
	forn (i, b.size()) {
		notl[b[i].fs].pb(i);
	}
	vector<int> ans(b.size());
	forn (i, n + 1) {
		forn (j, rotl[i].size()) {
			upd(rotl[i][j].fs, rotl[i][j].sc);
		}
		forn (j, notl[i].size()) {
			ans[notl[i][j]] = get(b[notl[i][j]].sc, n + 1);
		}
	}
	return ans;
}

int a[100010];

vector<int> num[100010];

pair<int, int> otr (vector<int> &nm, int i, int j) {
//	cerr << nm.size() << ' ' << i << ' ' << j << ' ' << endl;
	int l = i ? nm[i - 1] + 1 : 0;
	int r = (j < (int)nm.size()) ? nm[j] : n;
	return mp(l, r);
}

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	cin >> n;
	forn (i, n) {
		scanf("%d", &a[i]);
	}
	int m;
	cin >> m;
	vector<pair<int, int> > zap(m);
	forn (i, m) {
		scanf("%d%d", &zap[i].fs, &zap[i].sc);
		zap[i].fs--;
	}
	forn (i, n) {
		num[a[i]].pb(i);
	}
	vector<pair<pair<int, int>, int> > qqq;
	forn (i, 100010) {
		forn (j, num[i].size() + 1) {
			qqq.pb(mp(otr(num[i], j, j), 1));
		}
	}
	vector<pair<pair<int, int>, int> > www;
	forn (i, 100010) {
		if ((int)num[i].size() == 0) {
			continue;
		}
		for (int j = 0; 1; ) {
			int k = j;
			while (k + 1 < (int)num[i].size() && (k == j || num[i][k + 1] + num[i][k - 1] == 2 * num[i][k])) {
				++k;
			}

			www.pb(mp(otr(num[i], j, k + 1), 1));
			for (int l = j; l <= k + 1; ++l) {
				www.pb(mp(otr(num[i], l, l), -1));
			}

			if (k + 1 == (int)num[i].size()) {
				break;
			}
			j = k;
		}
	}
	vector<int> ans1 = occ(qqq, zap);
	vector<int> ans2 = occ(www, zap);
	vector<int> ans(m, 0);
	forn (i, m) {
		ans[i] = 100010 - ans1[i] + 1 - bool(ans2[i]);
//		cerr << 100010 - ans1[i] << ' ' << ans2[i] << endl;
		printf("%d\n", ans[i]);
	}
	return 0;
}