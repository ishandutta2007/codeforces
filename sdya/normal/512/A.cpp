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

const int maxN = 26;
bool g[maxN][maxN];
bool used[maxN];
vector < int > order;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < 26; ++i) {
		if (g[v][i] && !used[i]) {
			dfs(i);
		}
	}
	order.push_back(v);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector < string > s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int m = min(s[i].size(), s[j].size());
			bool ok = false;
			for (int k = 0; k < m; ++k) {
				if (s[i][k] != s[j][k]) {
					g[s[j][k] - 'a'][s[i][k] - 'a'] = 1;
					ok = true;
					break;
				}
			}
			if (!ok) {
				if (s[i].size() > s[j].size()) {
					printf("Impossible\n");
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			for (int k = 0; k < 26; ++k) {
				if (g[j][i] && g[i][k]) {
					g[j][k] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (g[i][i]) {
			printf("Impossible\n");
			return 0;
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i < order.size(); ++i) {
		printf("%c", 'a' + order[i]);
	}
	printf("\n");


	return 0;
}