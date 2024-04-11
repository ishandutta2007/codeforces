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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	vector < bool > a(n, true), b(n, true);
	vector < bool > usedA(n, false), usedB(n, false);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x - 1] = b[y - 1] = false;
	}

	int res = 0;
	for (int i = 1; i + 1 < n; ++i) {
		if (usedA[i]) {
			continue;
		}
		vector < int > p, q;
		usedA[n - 1 - i] = true;
		if (a[i]) {
			p.push_back(i);
		}
		if (b[i]) {
			q.push_back(i);
		}
		if (n - 1 - i != i) {
			if (a[n - 1 - i]) {
				p.push_back(n - 1 - i);
			}
			if (b[n - 1 - i]) {
				q.push_back(n - 1 - i);
			}
		}

		int a[2] = {0, 0};
		int b[2] = {0, 0};
		int best = 0;
		for (a[0] = 0; a[0] < 3; ++a[0]) {
			for (a[1] = 0; a[1] < 3; ++a[1]) {
				for (b[0] = 0; b[0] < 3; ++b[0]) {
					for (b[1] = 0; b[1] < 3; ++b[1]) {
						if (p.size() == 0 && (a[0] != 0 || a[1] != 0)) {
							continue;
						}
						if (p.size() == 1 && a[1] != 0) {
							continue;
						}
						if (q.size() == 0 && (b[0] != 0 || b[1] != 0)) {
							continue;
						}
						if (q.size() == 1 && b[1] != 0) {
							continue;
						}
						int current = (int)(a[0] != 0) + (int)(a[1] != 0) + (int)(b[0] != 0) + (int)(b[1] != 0);
						bool isOk = true;
						for (int x = 0; x < p.size(); ++x) {
							for (int y = 0; y < q.size(); ++y) {
								if (a[x] == 0 || b[y] == 0) {
									continue;
								}
								pair < int, int > u(p[x], (a[x] == 1 ? 0 : n - 1));
								pair < int, int > v((b[y] == 1 ? 0 : n - 1), q[y]);
								if (u.first + v.first == u.second + v.second || u.first - v.first == u.second - v.second) {
									isOk = false;
								}
							}
						}
						if (isOk) {
							best = max(best, current);
						}
					}
				}
			}
		}
		res += best;
	}
	printf("%d\n", res);

	return 0;
}