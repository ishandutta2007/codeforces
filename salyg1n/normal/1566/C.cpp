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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		a = '#' + a;
		b = '#' + b;
		int last0 = 0, last1 = 0;
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			int mex = 0;
			if (a[i] == '0' || b[i] == '0')
				last0 = i;
			if (a[i] == '1' || b[i] == '1')
				last1 = i;
			if (a[i] == '0' || b[i] == '0') {
				mex = 1;
				if (a[i] == '1' || b[i] == '1')
					mex = 2;
			}
			if (mex == 2) {
				dp[i] = dp[i - 1] + 2;
			}
			if (mex == 1) {
				dp[i] = max(dp[i - 1] + 1, last1? dp[last1 - 1] + 2 : 0);
			}
			if (mex == 0) {
				dp[i] = max({ dp[i - 1], last0 ? dp[last0 - 1] + 1 : 0, (last1 && last0) ? dp[min(last0, last1) - 1] + 2 : 0});
			}
		}
		cout << dp[n] << "\n";
	}

	return 0;
}