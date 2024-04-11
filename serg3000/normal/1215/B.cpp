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
	vector<int>a(n + 1), b(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			b[i] = 1;
		}
	}
	vector<int>pref(n);
	pref[0] = b[0];
	int c = 0;
	c += pref[0] % 2;
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + b[i];
		c += pref[i] % 2;
	}
	cout << c * (n - c + 1) << " " << n * (n + 1) / 2 - c * (n - c + 1);
	return 0;
}