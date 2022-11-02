#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
const int mod = 1e9 + 7;
signed main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	int x1 = 0, x2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			x1++;
		}
		if (s[i] == '?') {
			x2++;
		}
	}
	if (x1 != 0) {
		if (n - 2 * (x1 + x2) <= k) {
			string ans = "";
			int z = 0;
			for (int i = 0; i < n - 1; i++) {
				if (s[i + 1] == '*' && z == 0) {
					z = 1;
					for (int j = 0; j < k - (n - 2 * (x1 + x2)); j++) {
						ans += s[i];
					}
				}
				else {
					if (s[i + 1] != '?' && s[i] != '?' && s[i] != '*' && s[i + 1] != '*') {
						ans += s[i];
					}

				}
			}
			if (s[n - 1] != '?' && s[n - 1] != '*') {
				ans += s[n - 1];
			}
			cout << ans;
		}
		else {
			cout << "Impossible";
		}

	}
	else {
		if (n - 2 * x2 > k || n - x2 < k) {
			cout << "Impossible";
		}
		else {
			string ans;
			int zz = k - (n - 2 * x2);

			for (int i = 0; i < n - 1; i++) {
				if (s[i] != '?') {
					if (s[i + 1] != '?') {
						ans += s[i];
					}
					else {
						if (zz != 0) {
							ans += s[i];
							zz--;
						}
					}
				}
			}
			if (s[n - 1] != '?') {
				ans += s[n - 1];
			}
			cout << ans;
		}

	}
	return 0;
}