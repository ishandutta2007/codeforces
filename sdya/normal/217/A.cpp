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

const int maxN = 110;
int x[maxN], y[maxN];
int n;
bool used[maxN];

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		if (x[i] == x[v] || y[i] == y[v]) {
			dfs(i);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
			++res;
		}
	}

	cout << (res - 1) << endl;

	return 0;
}