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
#include <cassert>
#include <random>
#include <cstring>
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
#define mset multiset
#define vll __int128

//#define int long long
//#define DEBUG

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		input(a);
		a.push_back(10);
		vector<ll> st(11);
		st[0] = 1;
		for (int i = 1; i <= 10; ++i)
			st[i] = st[i - 1] * 10;
		ll ans = 0;
		k++;
		for (int i = 0; i < n; ++i) {
			if (k > 0) {
				ans += min(k, st[a[i + 1]] / st[a[i]] - 1) * st[a[i]];
				k -= min(k, st[a[i + 1]] / st[a[i]] - 1);
			}
		}
		ans += k * st[a[n-1]];
		cout << ans << "\n";
	}
	return 0;
}