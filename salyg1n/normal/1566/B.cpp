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
		string s;
		cin >> s;
		int n = s.size();
		vector<int> dp(n);
		if (s[0] == '1')
			dp[0] = 0;
		else
			dp[0] = 1;
		for (int i = 1; i < n; ++i) {
			if (s[i] == '1')
				dp[i] = dp[i - 1];
			else {
				if (s[i - 1] == '0')
					dp[i] = dp[i - 1];
				else
					dp[i] = dp[i - 1] + 1;
			}
		}
		cout << min(dp[n - 1], 2) << "\n";
	}

	return 0;
}