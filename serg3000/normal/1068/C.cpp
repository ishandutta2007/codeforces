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
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>g(n);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int c = 0;
	int c2 = 0;
	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
	}
	vector<int>a(n);
	vector<int>b(n);
	int l = 0;
	for (int i = 0; i < n; i++) {
		c = 0;
		c2 = 0;
		for (auto u : g[i]) {
			c++;
		}
		for (auto u : g[i]) {
			if (u < i) {
				c2++;
			}
		}
		if (c == 0) {
			cout << 1 << '\n';
			cout << l + 1 << " " << i + 1 << '\n';
			l++;
		}
		else {
			a[i] = l;
			b[i] = a[i];
			l += c - c2;
			cout << c << '\n';
			for (int j = 0; j < c2; j++) {
				cout << b[g[i][j]] + 1 << " " << i + 1 << '\n';
				b[g[i][j]] ++;
			}
			for (int j = 0; j < c - c2; j++) {
				cout << a[i] + 1 + j << " " << i + 1 << '\n';
			}
		}
	}

	return 0;
}