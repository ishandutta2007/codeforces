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
	vector<int>a(n);
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			x++;
		}
		else {
			y++;
		}
	}
	if (x * y == 0) {
		for (auto i : a) {
			cout << i << " ";
		}
	}
	else {
		sort(a.begin(), a.end());
		for (auto i : a) {
			cout << i << " ";
		}

	}
	return 0;
}