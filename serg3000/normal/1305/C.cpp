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
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	if (n >= m + 1) {
		cout << 0;
		return 0;
	}
	int c = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			c *= abs(a[i] - a[j]);
			if (c > m) {
				c %= m;
			}
		}
	}
	c %= m;
	cout << c;
	return 0;
}