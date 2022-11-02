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
	vector<int>a(n);
	forn(i, n) {
		cin >> a[i];
	}
	vector<int>l(n), r(n);
	vector<int>c(n + 1, -1), d(n + 1, -1);
	forn(i, n) {
		if (c[a[i]] == -1) {
			c[a[i]] = i;
		}
	}
	forn(i, n) {
		l[i] = c[a[i]];
	}
	for (int i = n - 1; i > -1; i--) {
		if (d[a[i]] == -1) {
			d[a[i]] = i;
		}
	}
	forn(i, n) {
		r[i] = d[a[i]];
	}
	vector<int>dp(n);
	vector<int>cnt(n + 1);
	forn(i, n) {
		cnt[a[i]]++;
	}
	forn(i, n) {
		if (i != 0) {
			dp[i] = dp[i - 1];
		}
		if (r[i] == i) {
			if (l[i] == 0) {
				dp[i] = max(dp[i], cnt[a[i]]);
			}
			else {
				dp[i] = max(dp[i], cnt[a[i]] + dp[l[i] - 1]);
			}
		}
	}
	vector<int>kek(n + 1);
	set<pair<int, int>>s;
	
	vector<int>masuf(n);
	for (int i = n - 1; i > -1; i--) {
		int x = a[i];
		s.erase({ kek[x], x });

		kek[x]--;
		s.insert({ kek[x], x });
		auto z = *s.begin();
		masuf[i] = -z.first;
	}
	int ans = 0;
	forn(i, n - 1) {
		ans = max(dp[i] + masuf[i + 1], ans);
	}
	ans = max(ans, dp[n - 1]);
	cout << n - ans;
	return 0;
}