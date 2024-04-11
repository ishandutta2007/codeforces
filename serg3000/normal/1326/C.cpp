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
mt19937 rnd(time(nullptr));
#define int long long
#define all(v) v.begin(), v.end()
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	vector<int>c(n);
	int cnt = 0;
	int fl = 0, v = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= n - k + 1) {
			if (fl == 0) {
				fl = 1;
				v = i;
			}
			cnt += a[i];
			c[i] = 1;
		}
	}
	int z = 0;
	int ans = 1;
	for (int i = v + 1; i < n; i++) {
		if (c[i] == 1) {
			ans *= (z + 1);
			if (ans > 998244353) {
				ans %= 998244353;
			}
			z = 0;
		}
		else {
			z++;
		}
		
	}
	cout << cnt << " " << ans % 998244353;
	return 0;
}