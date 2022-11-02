#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<ll>> a(n);
		for (auto& i : a) {
			int k;
			cin >> k;
			i.resize(k);
			for (auto& j : i)
				cin >> j;
		}
		vector<pair<ll, ll>> b(n);
		for (int i = 0; i < n; ++i) {
			ll l = 0, r = 1e12;
			while (r - l > 1) {
				ll m = (r + l) / 2;
				ll now = m;
				bool flag = true;
				for (int j = 0; j < a[i].size(); ++j) {
					if (a[i][j] >= now)
						flag = false;
					now++;
				}
				if (flag)
					r = m;
				else
					l = m;
			}
			b[i].first = r;
			b[i].second = a[i].size();
		}
		sort(all(b));
		ll ans = b[0].first, now = b[0].first + b[0].second;
		for (int i = 1; i < n; ++i) {
			if (now < b[i].first) {
				ans += b[i].first - now;
				now = b[i].first;
			}
			now += b[i].second;
		}
		cout << ans << "\n";
	}
	return 0;
}