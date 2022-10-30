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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5100;
int n;
char s[maxN][maxN];
int order[maxN];

bool comp(int x, int y) {
	for (int i = 0; i < n; ++i) {
		if (s[x][i] < s[y][i]) {
			return true;
		}
		if (s[x][i] > s[y][i]) {
			return false;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
		order[i] = i;
	}

	sort(order, order + n, comp);

	for (int i = 1; i < n; ++i) {
		int u = order[i - 1];
		int v = order[i];
		vector < int > a;
		a.push_back(u);
		a.push_back(v);
		bool f1 = false, f2 = false;
		for (int j = 0; j < n; ++j) {
			if (!f1 && s[u][j] == '0' && s[v][j] == '1') {
				a.push_back(j);
				f1 = true;
			}
			if (!f2 && s[v][j] == '0' && s[u][j] == '1') {
				a.push_back(j);
				f2 = true;
			}
		}

		for (int x = 0; x < a.size(); ++x) {
			for (int y = 0; y < a.size(); ++y) {
				for (int z = 0; z < a.size(); ++z) {
					if (s[a[x]][a[y]] == '1' && s[a[y]][a[z]] == '1' && s[a[z]][a[x]] == '1') {
						printf("%d %d %d\n", a[x] + 1, a[y] + 1, a[z] + 1);
						return 0;
					}
				}
			}
		}
	}

	printf("-1\n");

	return 0;
}