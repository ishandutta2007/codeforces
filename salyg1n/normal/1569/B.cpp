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

//#define int long long
//#define DEBUG

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> two;
		for (int i = 0; i < n; ++i)
			if (s[i] == '2')
				two.push_back(i);
		if (two.size() && two.size() <= 2) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<vector<char>> a(n, vector<char>(n, '='));
		for (int i = 0; i < two.size(); ++i) {
			int j = (i + 1) % two.size();
			a[two[i]][two[j]] = '+';
			a[two[j]][two[i]] = '-';
		}
		for (int i = 0; i < n; ++i)
			a[i][i] = 'X';
		for (auto& i : a) {
			for (auto& j : i)
				cout << j;
			cout << "\n";
		}

	}
	return 0;
}