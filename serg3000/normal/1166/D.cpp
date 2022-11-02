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
	int q;
	cin >> q;
	vector<int>st(55);
	st[0] = 1;
	for (int i = 1; i < 55; i++) {
		st[i] = st[i - 1] * 2;
	}
	for (int w = 0; w < q; w++) {
		int a, b, m;
		cin >> a >> b >> m;
		int v = 0;
		if (a == b) {
			cout << 1 << " " << a << '\n';
			continue;
		}
		vector<int>c(55);
		vector<int>d(55);
		c[0] = a;
		d[0] = a;
		for (int i = 1; i < 55; i++) {
			for (int j = 0; j < i; j++) {
				c[i] += c[j];
				d[i] += d[j];
			}
			d[i] += m;
			c[i] += 1;
			c[i] = min(c[i], 2000000000000000ll);
			d[i] = min(d[i], 2000000000000000ll);
		}
		int fl = 0;
		for (int i = 1; i < 55; i++) {
			if (c[i] <= b && d[i] >= b) {
				int x = b - c[i];
				for (int j = 1; j <= i; j++) {
					int ooo = i - j - 1;
					ooo = max(ooo, 0ll);
					ooo = st[ooo];
					int z = x / ooo;
					if (z <= m - 1) {
						c[j] += z;
					}
					else {
						c[j] += m - 1;
					}
					if (z <= m - 1) {
						for (int e = j + 1; e <= i; e++) {
							c[e] += z * st[e - j - 1];
						}
						x = b - c[i];
					}
					else {
						for (int e = j + 1; e <= i; e++) {
							c[e] += (m - 1) * st[e - j - 1];
						}
						x = b - c[i];
					}
				}
				cout << i + 1 << " ";
				for (int j = 0; j <= i; j++) {
					cout << c[j] << " ";
				}
				for (int j = 1; j <= i; j++) {
					int cnt = 0;
					for (int e = 0; e < j; e++) {
						cnt += c[e];
					}
					if (c[j] - cnt > m || c[j] - cnt <= 0) {
						while (1) {

						}
					}
				}
				if (c[i] != b) {
					while (1) {

					}
				}
				cout << '\n';
				fl = 1;
				break;
			}
		}
		if (fl == 0) {
			cout << -1 << '\n';
		}
	}
	return 0;
}