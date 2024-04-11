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
#define vll __int128

//#define int long long
//#define DEBUG

using namespace std;

bool prime(int a) {
	for (int i = 2; i * i <= a; ++i) {
		if (a % i == 0)
			return false;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n + 1);
	for (int i = 0; i <= m; ++i)
		a[0] += '.';
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = '.' + a[i];
	}
	vector<int> p(m + 1, 0);
	for (int j = 1; j <= m; ++j) {
		p[j] = p[j - 1];
		for (int i = 1; i <= n; ++i) {
			if (a[i-1][j] == 'X' && a[i][j-1] == 'X')
				p[j]++;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (p[r] - p[l] == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}