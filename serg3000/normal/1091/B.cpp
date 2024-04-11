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
	vector<int>x(n), y(n), a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	map<pair<int, int>, int>mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		mp[{a[i], b[i]}]++;
	}
	for (int i = 0; i < n; i++) {
		int z = 0;
		int tx = x[0] + a[i];
		int ty = y[0] + b[i];
		for (int j = 0; j < n; j++) {
			if (mp[{tx - x[j], ty - y[j]}] <= 0) {
				z = 1;
			}
		}
		if (z == 0) {
			cout << tx << " " << ty;
			return 0;
		}
	}
	return 0;
}