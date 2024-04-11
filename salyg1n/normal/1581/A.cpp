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
		ll n;
		cin >> n;
		ll res = 1;
		for (ll i = 3; i <= 2 * n; ++i) {
			res = (res * i) % (ll)(1e9 + 7);
		}
		cout << res << "\n";
	}
	return 0;
}