#include <malloc.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <deque>
#include <list>
#include <string>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <assert.h>
#include <stack>
#include <bitset>
#include <complex>

#ifndef LOCAL_MACHINE
#define trace(a) void()
#define tracearr(a, b) void()
#else
#define debug
#include "/home/victor/Dropbox/Public/trace.cpp"
#endif

using namespace std;

#define forn(i,j) for(int i = 0; i < int(j); ++i)
#define ford(i,j) for(int i = int(j) - 1; i >= 0; --i)
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin(); i != (c).end(); ++i)
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a)*(a))
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define y1 botva

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const string filename("");

int a[200010], b[200010];
map<int, int> q;

int c[400010];

int solve () {
	q.clear();
	int n, m, p;
	if (scanf("%d%d%d", &n, &m, &p) != 3) {
		return 1;
	}
	int k = 0;
	forn (i, n) {
		scanf("%d", &a[i]);
		if (!q.count(a[i])) {
			q[a[i]] = k++;
		}
		a[i] = q[a[i]];
	}
	forn (i, m) {
		scanf("%d", &b[i]);
		if (!q.count(b[i])) {
			q[b[i]] = k++;
		}
		b[i] = q[b[i]];
	}
	memset(c, 0, sizeof c);
	set<pair<int, int> > t;
	forn (i, k) {
		t.insert(mp(0, i));
	}
	forn (i, m) {
		t.erase(mp(c[b[i]], b[i]));
		c[b[i]]--;
		t.insert(mp(c[b[i]], b[i]));
	}
	vector<int> ans;
	forn (r, p) {
		for (int i = r, j = r; i < n; i += p) {
			while (j < n && ll(j - i) < ll(m) * ll(p)) {
				t.erase(mp(c[a[j]], a[j]));
				c[a[j]]++;
				t.insert(mp(c[a[j]], a[j]));
				j += p;
			}
			if (t.begin()->fs == 0 && (--t.end())->fs == 0) {
				ans.pb(i);
			}
			t.erase(mp(c[a[i]], a[i]));
			c[a[i]]--;
			t.insert(mp(c[a[i]], a[i]));
		}
	}
	sort(all(ans));
	cout << ans.size() << endl;
	forn (i, ans.size()) {
		printf("%d ", ans[i] + 1);
	}
	puts("");
	return 0;
}

int main ()
{
#ifdef LOCAL_MACHINE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	while (!solve());
#else
//#ifndef ONLINE_JUDGE
//	freopen((filename + ".in").data(), "rt", stdin);
//	freopen((filename + ".out").data(), "wt", stdout);
//#endif
	solve();
#endif
	return 0;
}