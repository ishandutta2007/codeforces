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
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
//#define int long long
using namespace std;
vector<vector<int>>g;
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	forn(w, t) {
		int n;
		cin >> n;
		vector<int>a(n);
		forn(i, n) {
			cin >> a[i];
		}
		map<int, int>c;
		map<int, int>d;
		forn(i, n) {
			d[a[i]]++;
		}
		int f = 1;
		for (auto u : d) {
			if (u.second > (n + 1) / 2) {
				cout << -1 << '\n';
				f = 0;
				break;
			}
		}
		if (f == 0) {
			continue;
		}
		int cnt = 0;
		forn(i, n - 1) {
			if (a[i] == a[i + 1]) {
				cnt++;
				c[a[i]] += 2;
			}
		}
		c[a[0]]++;
		c[a[n - 1]]++;
		cnt++;
		int ma = 0;
		forn(i, n) {
			ma = max(ma, c[i + 1]);
		}
		if (ma <= cnt) {
			cout << cnt - 1 << '\n';
			continue;
		}
		else {
			cout << ma - 2 << '\n';
		}
	}
	return 0;
}