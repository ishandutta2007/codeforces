#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#define ll long long
#define x first
#define y second
#define res resize
#define pb push_back
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
#define int long long
using namespace std;
struct edge {};
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<double>a(n), v(n), b(n), c(n);
	forn(i, n) {
		cin >> a[i];
	}
	forn(i, n) {
		cin >> v[i];
	}
	double l = 0, r = 1e18;
	
	forn(w, 400) {
		double m = (r + l) / 2;
		double x = -1e18, y = 1e18;
		forn(i, n) {
			b[i] = a[i] - v[i] * m;
			x = max(x, b[i]);
			c[i] = a[i] + v[i] * m;
			y = min(y, c[i]);
		}
		if (x < y) {
			r = m;
		}
		else {
			l = m;
		}
	}
	cout.precision(40);
	cout << l;
	return 0;
}