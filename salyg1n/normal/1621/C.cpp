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
#include <climits>
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
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

//#define int long long
//#define DEBUG

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<bool> used(n + 1, false);
	vector<int> ans(n + 1, 0);
	cout << "? " << 1 << endl;
	used[1] = true;
	int last;
	cin >> last;
	for (int i = 1; i <= n;) {
		cout << "? " << i << endl;
		int x;
		cin >> x;
		if (x == 0)
			exit(0);
		
		if (used[x]) {
			ans[x] = last;
			while (i <= n && used[i])
				i++;
			if (i <= n) {
				cout << "? " << i << endl;
				cin >> last;
				used[last] = true;
			}
			continue;
		}
		used[x] = true;
		ans[x] = last;
		last = x;
	}
	vector<int> res(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		res[ans[i]] = i;
	cout << "! ";
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}