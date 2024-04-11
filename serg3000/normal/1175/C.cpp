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
mt19937 rnd(time(NULL));
#define int long long
signed main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n, k;
		cin >> n >> k;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans1 = 1e18;
		int ans2 = 0;
		for (int i = 0; i < n - k; i++) {
			if (ans1 > (-a[i] + a[i + k] + 1) / 2) {
				ans2 = (a[i] + a[i + k]) / 2;
			}
			ans1 = min(ans1, (-a[i] + a[i + k] + 1) / 2);
		}
		cout << ans2 << '\n';
	}
	return 0;
}