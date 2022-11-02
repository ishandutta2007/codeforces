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
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>suf(n);
	suf[n - 1] = a[n - 1];
	for (int i = n - 2; i > -1; i--) {
		suf[i] = suf[i + 1] + a[i];
	}
	int ans = suf[0];
	suf[0] = -1e18;
	sort(suf.begin(), suf.end());
	for (int i = n - 1; i > n - k; i--) {
		ans += suf[i];
	}
	cout << ans;
	return 0;
}