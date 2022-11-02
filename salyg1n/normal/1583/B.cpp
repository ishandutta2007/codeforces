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

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<bool> a(n + 1, true);
		for (int i = 0; i < m; ++i) {
			int A, B, C;
			cin >> A >> B >> C;
			a[B] = false;
		}
		int ind = -1;
		for (int i = 1; i <= n; ++i) {
			if (a[i]) {
				ind = i;
				break;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i == ind)
				continue;
			cout << i << " " << ind << "\n";
		}
		cout << "\n";
	}
	return 0;
}