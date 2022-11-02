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

const int maxN = 210;
int n, a[maxN];
vector < int > g[maxN];
bool visited[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		int m;
		cin >> m;
		g[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}

	int res = 1000000000;
	for (int start = 1; start <= 3; ++start) {
		memset(visited, 0, sizeof(visited));
		int current = n;
		int color = start;
		while (true) {
			while (true) {
				bool changes = false;
				for (int i = 1; i <= n; ++i) {
					if (visited[i]) {
						continue;
					}
					bool ok = true;
					for (int j = 0; j < g[i].size(); ++j) {
						if (!visited[g[i][j]]) {
							ok = false;
							break;
						}
					}
					if (ok && a[i] == color) {
						visited[i] = true;
						changes = true;
					}
				}
				if (!changes) {
					break;
				}
			}
			color += 1;
			if (color == 4) {
				color = 1;
			}
			bool ok = true;
			for (int i = 1; i <= n; ++i) {
				if (!visited[i]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				break;
			}
			++current;
		}
		res = min(res, current);
	}
	cout << res << endl;


	return 0;
}