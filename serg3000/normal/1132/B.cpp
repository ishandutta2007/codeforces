#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GGC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
signed main() {
	
	int n;
	cin >> n;
	vector<int>a(n);
	int summ = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		summ += a[i];
	}

	int m;
	cin >> m;
	vector<int>q(m);
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i++) {
		cin >> q[i];
		q[i]--;
		cout << summ - a[n - q[i] - 1] << '\n';
	}

	return 0;
}