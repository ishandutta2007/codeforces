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
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("no-stack-protector")
#define int long long
signed main() {
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector<int>a(n);
	vector<int>b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	if (k >= min(n, m)) {
		cout << -1;
		return 0;
	}
	int l = 0;
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		while (1) {
			if (l >= m) {
				ans = -1;
				break;
			}
			if (b[l] < a[i] + ta) {
				l++;
			}
			else {
				if (l + k - i >= m) {
					cout << -1;
					return 0;
				}
				ans = max(ans, b[l + k - i] + tb);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}