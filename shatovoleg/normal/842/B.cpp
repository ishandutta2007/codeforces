#include <bits/stdc++.h>

// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <random>
// #include <string>
// #include <vector>
// #include <queue>
// #include <map>
// #include <set>

using namespace std;
typedef long long ll;
typedef long double ld;

#define len(v) ((signed)v.size())
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define int ll
#define kek pop_back
#define F first
#define S second
// #define pii pair<int, int>
mt19937 rnd(5654897);
#define rand rnd()

#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << endl;
#else
#define debug(x) ;
#endif

const int INF = numeric_limits<int>::max() >> 2;

template<class T1, class T2>
bool cmin(T1 &a, const T2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T1, class T2>
bool cmax(T1 &a, const T2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

inline void run();

void UseFiles(const string &s) {
#ifndef LOCAL
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

signed main() {
	// UseFiles("sequence");
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef LOCAL
	// assert(freopen("test.in", "r", stdin));
	#endif
	run();
}

int sq_dist(int x, int y) {
	return x * x + y * y;
}

void run() {
	int R, d;
	cin >> R >> d;
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y, r;
		cin >> x >> y >> r;
		if (sq_dist(x, y) < (R - d + r) * (R - d + r))
			continue;
		if (sq_dist(x, y) > (R - r) * (R - r))
			continue;
		++cnt;
	}
	cout << cnt << endl;
}