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
		ll n;
		cin >> n;
		vector<ll> a(n);
		input(a);
		sort(all(a));
		ll sum = 0;
		for (auto i : a)
			sum += i;
		sum *= 2;
		if (sum % n) {
			cout << "0\n";
			continue;
		}
		ll ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans += ub(a.begin() + i + 1, a.end(), sum / n - a[i]) - lb(a.begin() + i + 1, a.end(), sum / n - a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}