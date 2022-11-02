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
		s = '#' + s;
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			a[i] = a[i - 1] + (s[i] == 'a');
		int l = -1, r = -1;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; j += 2) {
				if (a[j] - a[i - 1] == (j - i + 1) / 2) {
					l = i, r = j;
				}
			}
		}
		cout << l << " " << r << "\n";
	}
	return 0;
}