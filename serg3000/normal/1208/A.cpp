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
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	for (int w = 0; w < t; w++) {
		int a, b, n;
		cin >> a >> b >> n;
		int z = n % 3;
		if (z == 2) {
			cout << (a ^ b) << '\n';
		}
		if (z == 0) {
			cout << a << '\n';
		}
		if (z == 1) {
			cout << b << '\n';
		}
	}

	return 0;
}