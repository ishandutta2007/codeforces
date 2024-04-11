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
		int a, b, c;
		cin >> a >> b >> c;
		int c1 = c;
		if (b >= a) {
			c -= (b - a);
			c++;
			c /= 2;
			if (c < 0) {
				c = 0;
			}
			cout << c << '\n';
		}
		else {
			int ans = 0;
			c -= (a - b);
			c++;
			c /= 2;
			if ((a + b + c1) % 2 == 0 && (b + c1 >= a)) {
				c++;
			}
			if (c < 0) {
				c = 0;
			}
			cout << c1 - c + 1<< '\n';
		}
	}
	

	return 0;
}