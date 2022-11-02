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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int ans = 0;
	vector<int>c(n);
	for (int i = 0; i < n; i++) {
		c[i] = s[i] - '0';
		ans += c[i];
	}
	for (int j = 0; j < 1000; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (j >= b[i]) {
				cnt += (((j - b[i]) / a[i] + c[i] + 1)) % 2;
			}
			else {
				cnt += c[i];
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}