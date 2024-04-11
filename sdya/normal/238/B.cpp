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
const int inf = 1000000000;
int n, h;
int a[maxN];

int c[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &h);

	vector < pair < int, int > > p;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		p.push_back(make_pair(a[i], i));
	}
	sort(p.begin(), p.end());

	vector < int > indices;
	for (int i = 0; i < p.size() && i < 6; ++i) {
		indices.push_back(p[i].second);
	}

	reverse(p.begin(), p.end());
	for (int i = 0; i < p.size() && i < 6; ++i) {
		indices.push_back(p[i].second);
	}

	sort(indices.begin(), indices.end());
	indices.resize(unique(indices.begin(), indices.end()) - indices.begin());

	int res = inf, mask = -1;
	int k = indices.size();
	for (int i = 0; i < (1 << k); ++i) {
		int mx = 0, mn = inf;
		for (int x = 0; x < k; ++x) {
			for (int y = 0; y < k; ++y) {
				if (x == y) {
					continue;
				}
				int value = a[indices[x]] + a[indices[y]];
				int u = (bool)(i & (1 << x));
				int v = (bool)(i & (1 << y));
				if (u + v == 1) {
					value += h;
				}
				mx = max(mx, value);
				mn = min(mn, value);
			}
		}
		if (mx - mn < res) {
			res = mx - mn;
			mask = i;
		}
	}

	for (int i = 1; i <= n; ++i) {
		c[i] = 1;
	}
	for (int i = 0; i < k; ++i) {
		if (mask & (1 << i)) {
			c[indices[i]] = 2;
		}
	}

	printf("%d\n", res);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", c[i]);
	}
	printf("\n");



	return 0;
}