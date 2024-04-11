#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
int n, m, k;
vector < int > g[maxN];
bool used[maxN];

void dfs(int v, int &cnt) {
	used[v] = true;
	++cnt;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], cnt);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	long long a = 0, b = 0, s = 0, t = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			int cnt = 0;
			dfs(i, cnt);
			if (cnt == 1) {
				++a;
			} else {
				++b;
				s += min(cnt, k);
				if (cnt < k) {
					t += k - cnt;
				}
			}
		}
	}

	if (k == 1) {
		if (a + b == 1) {
			cout << 0 << endl;
		} else {
			cout << a + b - 2 << endl;
		}
		return 0;
	}

	long long best = n;
	for (long long x = 0; x <= a && x <= t; ++x) {
		int left_bound = (max(0LL, 2 * b + a - s - 2 - 2 * x) + 1LL) / 2LL;
		int right_bound = (a - x) / 2;
		if (left_bound <= right_bound && x + left_bound < best) {
			best = x + left_bound;
		}
	}

	cout << best << endl;
	
	return 0;
}