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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 40;
int n, m, k;
string used[maxN][maxN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		if (s == "+1") {
			int x, y;
			cin >> x >> y;
			string name;
			cin >> name;

			bool ok = false;
			for (int j = x; j <= n && !ok; ++j) {
				int start = (j == x ? y : 1);
				for (int u = start; u <= m; ++u) {
					if (used[j][u].size() == 0) {
						ok = true;
						used[j][u] = name;
						break;
					}
				}
			}
		} else {
			string name;
			cin >> name;
			bool ok = false;
			for (int j = 1; j <= n && !ok; ++j) {
				for (int u = 1; u <= m; ++u) {
					if (used[j][u] == name) {
						printf("%d %d\n", j, u);
						ok = true;
						used[j][u].clear();
						break;
					}
				}
			}
			if (!ok) {
				printf("-1 -1\n");
			}
		}
	}


	return 0;
}