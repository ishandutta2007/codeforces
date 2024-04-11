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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 150;

long long get(long long n) {
	return (n * (n - 1) * (n - 2)) / 6;
}

int get2(int n) {
	return n * (n - 1) / 2;
}

int g[maxN][maxN];

int calc() {
	int res = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = i + 1; j < 100; ++j) {
			for (int k = j + 1; k < 100; ++k) {
				if (g[i][j] && g[i][k] && g[j][k]) {
					++res;
				}
			}
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int old = n;

	int m = 0;
	//while (n) {
		for (int i = 88; i >= 3; --i) {
			int t = get(i);
			if (n >= t) {
				n -= t;
				for (int j = 0; j < i; ++j) {
					for (int k = j + 1; k < i; ++k) {
						g[m + j][m + k] = g[m + k][m + j] = 1;
					}
				}
				m += i;
				break;
			}
		}

	int m1 = (100 - m);

	for (int k = m; k < m + m1; ++k) {
		for (int i = m; i >= 2; --i) {
			if (n >= get2(i)) {
				n -= get2(i);
				for (int x = 0; x < i; ++x) {
					g[k][x] = g[x][k] = 1;
				}
				break;
			}
		}
	}

	m += m1;

	//}

	/*if (m > 200) {
		m = 100;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				g[i][j] = (i != j);
			}
		}

		int total = calc();
		while (total != old) {
			bool updates = false;
			for (int i = 0; i < m; ++i) {
				for (int j = i + 1; j < m; ++j) {
					if (g[i][j] == 0) {
						continue;
					}

					int cur = 0;
					for (int k = 0; k < m; ++k) {
						if (k != i && k != j && g[i][k] && g[j][k]) {
							++cur;
						}
					}
					if (total - cur >= old) {
						total -= cur;
						g[i][j] = g[j][i] = 0;
						updates = true;
					}
				}
			}
			if (!updates) {
				vector < int > order(m);
				for (int i = 0; i < m; ++i) {
					order[i] = i;
				}
				random_shuffle(order.begin(), order.end());
				int cnt = 0;
				for (int i = 0; i < m && !updates; ++i) {
					for (int j = i + 1; j < m && !updates; ++j) {
						if (g[order[i]][order[j]] == 0) {
							++cnt;
							if (cnt == 50) {
								updates = true;
							}
							g[order[i]][order[j]] = g[order[j]][order[i]] = 1;
						}
					}
				}
				total = calc();
			}
		}
		printf("%d\n", m);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%d", g[i][j]);
			}
			printf("\n");
		}
		return 0;
	}*/

	//cerr << n << endl;
	//cerr << calc() << endl;
	printf("%d\n", m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}