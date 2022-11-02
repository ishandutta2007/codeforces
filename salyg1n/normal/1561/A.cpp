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

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		input(a);
		bool flag1 = true, flag2 = true;
		int ans = 0;
		for (int i = 0; i <= n * 2; ++i) {
			if (!flag1 && !flag2)
				break;
			ans++;
			if (i % 2)
				flag1 = false;
			else
				flag2 = false;
			for (int j = 0 + (i % 2); j < n-1; j += 2) {
				if (a[j] > a[j + 1]) {
					swap(a[j], a[j + 1]);
					if (i % 2)
						flag1 = true;
					else
						flag2 = true;
				}
			}
		}
		cout << ans - 2 << '\n';
	}
	return 0;
}