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
	string s;
	cin >> s;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}
	vector<int>b;
	vector<int>c;
	for (int i = n / 2; i > -1; i--) {
		if (a[i] != 0) {
			for (int j = i; j < n; j++) {
				b.push_back(a[j]);
			}
			int z = 0;
			for (int j = n - 2 * i; j < n - i; j++) {
				b[j] += a[z];
				z++;
			}
			break;
		}
	}
	for (int i = n / 2 + 1; i < n; i++) {
		if (a[i] != 0) {
			for (int j = 0; j < i; j++) {
				c.push_back(a[j]);
			}
			int z = i;
			for (int j = 2 * i - n; j < i; j++) {
				c[j] += a[z];
				z++;
			}
			break;
		}
	}
	int x1 = 0;
	int x2 = 0;
	for (int i = (int)b.size() - 1; i > 0; i--) {
		if (b[i] >= 10) {
			b[i] -= 10;
			b[i - 1]++;
		}
	}
	if (b[0] >= 10) {
		b[0] -= 10;
		x1 = 1;
	}
	for (int i = (int)c.size() - 1; i > 0; i--) {
		if (c[i] >= 10) {
			c[i] -= 10;
			c[i - 1]++;
		}
	}
	if (c.size() == 0) {
		if (x1 == 1) {
			vector<int>b2(1, 1);
			for (auto u : b) {
				b2.push_back(u);
			}
			b = b2;
		}
		for (auto u : b) {
			cout << u;
		}
		return 0;
	}
	if (c[0] >= 10) {
		c[0] -= 10;
		x2 = 1;
	}
	if ((int)b.size() + x1 > (int)c.size() + x2) {
		if (x1 == 1) {
			cout << 1;
		}
		for (auto u : c) {
			cout << u;
		}
		return 0;
	}
	else {
		if ((int)b.size() + x1 < (int)c.size() + x2) {
			if (x2 == 1) {
				cout << 1;
			}
			for (auto u : b) {
				cout << u;
			}
			return 0;
		}
		else {
			if (x1 == 1) {
				vector<int>b2(1, 1);
				for (auto u : b) {
					b2.push_back(u);
				}
				b = b2;
			}
			if (x2 == 1) {
				vector<int>c2(1, 1);
				for (auto u : c) {
					c2.push_back(u);
				}
				c = c2;
			}
			for (int i = 0; i < (int)b.size(); i++) {
				if (c[i] < b[i]) {
					for (auto u : c) {
						cout << u;
					}
					return 0;
				}
				if (c[i] > b[i]) {
					for (auto u : b) {
						cout << u;
					}
					return 0;
				}
			}
		}
	}
	for (auto u : b) {
		cout << u;
	}
	return 0;
}