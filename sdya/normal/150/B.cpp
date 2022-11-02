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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;

vector < int > g[maxN];
int n, m, k;
bool used[maxN];

const long long P = 1000000007LL;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		if (i + k - 1 <= n) {
			for (int l = i, r = i + k - 1; l < r; ++l, --r) {
				g[l].push_back(r);
				g[r].push_back(l);
			}
		}
	}

	long long res = 1LL;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i);
			res *= (long long)(m);
			res %= P;
		}
	}
	cout << res << endl;

	return 0;
}