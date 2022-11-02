//#define _GLIBCXX_DEBUG
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

//#define int long long
//#define DEBUG

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> x(n), y(m);
		input(x);
		input(y);
		vector<pair<int, int>>	px, py, pxy, pyx;
		map<int, vector<int>> xx, yy;
		for (int i = 0; i < k; ++i) {
			int X, Y;
			cin >> X >> Y;
			bool inx = (*lower_bound(all(x), X) == X), iny = (*lower_bound(all(y), Y) == Y);
			if (inx && !iny) {
				px.push_back({ X, Y });
				pxy.push_back({ Y, X });
				xx[X].push_back(Y);
			}
			if (!inx && iny) {
				py.push_back({ Y, X });
				pyx.push_back({ X, Y });
				yy[Y].push_back(X);
			}
		}
		for (auto& i : xx)
			sort(all(i.second));
		for (auto& i : yy)
			sort(all(i.second));
		sort(all(pxy));
		sort(all(pyx));
		ll ans = 0;
		for (int i = 0; i < px.size(); ++i) {
			auto lb = lower_bound(all(y), px[i].second), ub = upper_bound(all(y), px[i].second);
			int br = *lb;
			--ub;
			int mr = *ub;
			ans += (lower_bound(all(pxy), make_pair(br, -1)) - lower_bound(all(pxy), make_pair(mr, -1)));
			ans -= (lower_bound(all(xx[px[i].first]), br) - lower_bound(all(xx[px[i].first]), mr));
		}
		for (int i = 0; i < py.size(); ++i) {
			auto lb = lower_bound(all(x), py[i].second), ub = upper_bound(all(x), py[i].second);
			int br = *lb;
			--ub;
			int mr = *ub;
			ans += (lower_bound(all(pyx), make_pair(br, -1)) - lower_bound(all(pyx), make_pair(mr, -1)));
			ans -= (lower_bound(all(yy[py[i].first]), br) - lower_bound(all(yy[py[i].first]), mr));
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}