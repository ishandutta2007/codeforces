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

signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>p(n);
	forn(i, n) {
		cin >> p[i];
	}
	vector<int>l(n), r(n);
	firn(i, n) {
		if (p[i] > p[i - 1]) {
			l[i] = l[i - 1] + 1;
		}
		else {
			l[i] = 0;
		}
	}
	for (int i = n - 2; i > -1; i--) {
		if (p[i] > p[i + 1]) {
			r[i] = r[i + 1] + 1;
		}
	}
	int ma = 0;
	forn(i, n) {
		ma = max(ma, l[i]);
	}
	int z = 0;
	forn(i, n) {
		if (l[i] == ma) {
			z++;
		}
		if (r[i] == ma) {
			z++;
		}
	}
	if (z > 2) {
		cout << 0;
		return 0;
	}
	int ans = 0;
	forn(i, n) {
		if (l[i] == r[i] && l[i] == ma && ma % 2 == 0) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}