#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, a[maxN];

int solve(int index, int l, int r) {
	if (l == index && r == index) {
		return 0;
	}
	int res = 0;
	vector < int > x, y;
	for (int i = l; i <= r; ++i) {
		if (i < index) {
			x.push_back(a[i]);
		}
		if (i > index) {
			y.push_back(a[i]);
		}
	}
	reverse(x.begin(), x.end());
	for (int i = 30; i >= 0; --i) {
		int value = (a[index] & (1 << i));
		vector < int > nx, ny;
		if (value == 0) {
			bool have = false;
			for (int j = 0; j < x.size(); ++j) {
				if (x[j] & (1 << i)) {
					have = true;
					nx.push_back(x[j]);
				}
			}
			for (int j = 0; j < y.size(); ++j) {
				if (y[j] & (1 << i)) {
					have = true;
					ny.push_back(y[j]);
				}
			}
			if (have) {
				res ^= (1 << i);
				x = nx;
				y = ny;
			}
		} else {
			bool have = false;
			for (int j = 0; j < x.size(); ++j) {
				if (x[j] & (1 << i)) {
					break;
				} else {
					have = true;
					nx.push_back(x[j]);
				}
			}
			for (int j = 0; j < y.size(); ++j) {
				if (y[j] & (1 << i)) {
					break;
				} else {
					have = true;
					ny.push_back(y[j]);
				}
			}
			if (have) {
				res ^= (1 << i);
				x = nx;
				y = ny;
			} else {
				for (int j = 0; j < x.size(); ++j) {
					if (x[j] & (1 << i)) {
						nx.push_back(x[j]);
					}
				}
				for (int j = 0; j < y.size(); ++j) {
					if (y[j] & (1 << i)) {
						ny.push_back(y[j]);
					}
				}
				x = nx;
				y = ny;
			}
		}
	}
	return res;
}

void gen() {
	int n = 100;
	cout << n << endl;
	for (int i = 1; i <= n; ++i) {
		cout << rand() << endl;
	}
}

int trivial() {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			vector < int > b;
			for (int k = i; k <= j; ++k) {
				b.push_back(a[k]);
			}
			sort(b.rbegin(), b.rend());
			res = max(res, b[0] ^ b[1]);
		}
	}
	return res;
}

int solve() {
	int res = 0;
	for (int i = 30; i >= 0; --i) {
		bool zeroes = false;
		bool ones = false;
		for (int j = 0; j < n; ++j) {
			if (a[j] & (1 << i)) {
				ones = true;
			} else {
				zeroes = true;
			}
		}
		
		if (!ones || !zeroes) {
			continue;
		}

		for (int j = 0; j < n; ++j) {
			if (a[j] & (1 << i)) {
				int l = j;
				int r = j;
				for (int k = l - 1; k >= 0; --k) {
					if (a[k] & (1 << i)) {
						break;
					} else {
						l = k;
					}
				}
				for (int k = r + 1; k < n; ++k) {
					if (a[k] & (1 << i)) {
						break;
					} else {
						r = k;
					}
				}
				res = max(res, solve(j, l, r));
			}
		}
		break;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	cout << solve() << endl;

	/*while (true) {
		n = 25;
		for (int i = 0; i < n; ++i) {
			a[i] = rand();
		}
		if (trivial() != solve()) {
			cout << trivial() << endl;
			cout << solve() << endl;
			cout << n << endl;
			for (int i = 0; i < n; ++i) {
				cout << a[i] << endl;
			}
			exit(0);
			return 0;
		}
	}*/
	return 0;
}