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
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

//#define int long long
//#define DEBUG

using namespace std;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, m, k;
		cin >> n >> m >> k;
		k--;
		if (m > n * (n - 1) / 2) {
			cout << "NO\n";
			continue;
		}
		if (k <= 0) {
			cout << "NO\n";
			continue;
		}
		if (k == 1) {
			if (n == 1)
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}
		if (k == 2) {
			if (m >= n * (n - 1) / 2)
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}
		if (m < n - 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}