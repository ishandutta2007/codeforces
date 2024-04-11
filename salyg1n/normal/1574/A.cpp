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
		string s;
		for (int i = 0; i < n; ++i)
			s += '(';
		for (int i = 0; i < n; ++i) {
			s += ')';
		}
		cout << s << "\n";
		for (int i = n - 1; i > 0; --i) {
			swap(s[i], s[2 * n - i - 1]);
			cout << s << "\n";
			swap(s[i], s[2 * n - i - 1]);
		}
	}

	return 0;
}