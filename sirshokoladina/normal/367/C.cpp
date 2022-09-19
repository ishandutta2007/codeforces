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

int w[100010];

ll calc (ll n) {
	ll ans = n * (n - 1) / 2 + 1;
	if (n % 2 == 0) {
		ans += n / 2 - 1;
	}
	cerr << n << ' ' << ans << endl;
	return ans;
}

int solve () {
	int n, m;
	if (!(cin >> n >> m)) {
		return 1;
	}
	forn (i, m) {
		int x;
		scanf("%d%d", &x, &w[i]);
	}
	sort(w, w + m);
	reverse(w, w + m);
	int ans = 0;
	for (int i = 1; i <= m && calc(i) <= ll(n); ++i) {
		ans += w[i - 1];
	}
	cout << ans << endl;
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