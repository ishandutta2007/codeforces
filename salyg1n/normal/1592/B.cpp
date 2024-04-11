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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		input(a);
		auto b = a;
		sort(all(b));
		string ans = "YES";
		for (int i = 0; i < n; ++i) {
			if (i - 0 < x && n - 1 - i < x && a[i] != b[i])
				ans = "NO";
		}
		cout << ans << "\n";
	}
	return 0;
}