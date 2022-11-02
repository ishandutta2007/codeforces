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
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = n;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (a[m] - a[i] <= a[i]) {
				l = m;
			}
			else {
				r = m;
			}
		}
		cnt += l - i;
	}
	cout << cnt;
	return 0;
}