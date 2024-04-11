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

int c[100010];
int k[20];

bool bad[1 << 20];
int s[1 << 20];

int solve () {
	s[0] = 0;
	forn (i, 1 << 20) {
		s[i] = (i & 1) + s[i >> 1];
	}
	int n, m, d;
	if (!(cin >> n >> m >> d)) {
		return 1;
	}
	forn (i, m) {
		int k;
		cin >> k;
		forn (j, k) {
			int t;
			scanf("%d", &t);
			c[--t] = i;
		}
	}
	memset(k, 0, sizeof k);
	memset(bad, 0, sizeof bad);
	int msk = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && j - i < d) {
			if (k[c[j]] == 0) {
				msk += 1 << c[j];
			}
			k[c[j]]++;
			j++;
		}
		if (j - i == d) {
			bad[(1 << m) - 1 - msk] = 1;
		}
		k[c[i]]--;
		if (k[c[i]] == 0) {
			msk -= 1 << c[i];
		}
	}
	int mn = m;
	ford (i, 1 << m) {
		forn (j, m) {
			bad[i] |= bad[i | (1 << j)];
		}
		if (!bad[i]) {
			mn = min(mn, s[i]);
		}
	}
	cout << mn << endl;
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