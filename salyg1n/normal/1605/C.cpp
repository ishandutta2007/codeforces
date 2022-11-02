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
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define vll __int128
//#define x first
//#define y second

//#define int long long
//#define DEBUG

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == 'a' && s[i + 1] == 'a') {
			cout << 2 << "\n";
			return;
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if (s[i] == 'a' && s[i + 2] == 'a') {
			cout << 3 << "\n";
			return;
		}
	}
	for (int i = 0; i < n - 3; ++i) {
		if (s[i] == 'a' && s[i + 3] == 'a' && ((s[i + 1] == 'b' && s[i + 2] == 'c') || (s[i + 1] == 'c' && s[i + 2] == 'b'))) {
			cout << 4 << "\n";
			return;
		}
	}
	for (int i = 0; i < n -6; ++i) {
		if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 6] == 'a' && ((s[i + 1] == 'b' && s[i + 2] == 'b' && s[i + 4] == 'c' && s[i + 5] == 'c') || (s[i + 1] == 'c' && s[i + 2] == 'c' && s[i + 4] == 'b' && s[i + 5] == 'b'))) {
			cout << 7 << "\n";
			return;
		}
	}
	cout << -1 << "\n";
	return;
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