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

int kx[100010], ky[100010], kz[100010];

int solve () {
	string s;
	if (!getline(cin, s)) {
		return 1;
	}
	kx[0] = ky[0] = kz[0] = 0;
	forn (i, s.size()) {
		kx[i + 1] = kx[i] + (s[i] == 'x');
		ky[i + 1] = ky[i] + (s[i] == 'y');
		kz[i + 1] = kz[i] + (s[i] == 'z');
	}
	int m;
	cin >> m;
	forn (i, m) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		int x = kx[r] - kx[l];
		int y = ky[r] - ky[l];
		int z = kz[r] - kz[l];
		if (r - l < 3 || (abs(x - y) < 2 && abs(x - z) < 2 && abs(y - z) < 2)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

int main ()
{
#ifdef LOCAL_MACHINE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	solve();
#else
//#ifndef ONLINE_JUDGE
//	freopen((filename + ".in").data(), "rt", stdin);
//	freopen((filename + ".out").data(), "wt", stdout);
//#endif
	solve();
#endif
	return 0;
}