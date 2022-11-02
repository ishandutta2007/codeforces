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

signed main() {
	int n, m;
	cin >> n >> m;
	int c = 0;
	for (int i = 1; i <= n; i++) {
		c += max(0ll, n - 2 * i);
	}
	if (m > c) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int cnt = n;
	while (cnt >= 1) {
		if (c - (cnt - 1) / 2 >= m) {
			a[cnt - 1] = 1e9 - 3 * n * cnt;
			c -= (cnt - 1) / 2;
			cnt--;
		}
		else {
			a[cnt - 1] = cnt - 1 - ((cnt - 1) / 2 - (c - m)) * 2 + 1 + cnt - 1;
			break;
		}
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}