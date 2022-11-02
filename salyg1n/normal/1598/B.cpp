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
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define ft first
#define sc second
#define vec vector

//#define int long long
//#define DEBUG

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> a(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 5; ++j) {
				int x;
				cin >> x;
				a[i].push_back(x);
			}
		}
		string ans = "NO\n";
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (i == j)
					continue;
				int cnti = 0, cntj = 0, cntij = 0;
				for (auto& k : a) {
					if (k[i] && k[j])
						cntij++;
					else if (k[i])
						cnti++;
					else if (k[j])
						cntj++;
				}
				if (cnti + cntj + cntij == n && cnti <= n / 2 && cntj <= n / 2)
					ans = "YES\n";
			}
		}
		cout << ans;
	}
	return 0;
}