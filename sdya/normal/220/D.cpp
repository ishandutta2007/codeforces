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

const int P = 1000000007;
int n, m;

int get(int n, int mode) {
	if (mode == 0) {
		return 1 + (n / 2);
	} else {
		return (n + 1) / 2;
	}
}

int gcd(int x, int y) {
	if (x == 0 || y == 0) {
		return x + y;
	}
	if (x > y) {
		return gcd(x % y, y);
	} else {
		return gcd(y % x, x);
	}
}

long long cnk2(long long n) {
	return ((n * (n - 1)) / 2LL) % P;
}

const int maxN = 4003;
int ways[maxN];
int p[maxN][maxN];

void add(int dx, int dy) {
	
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			if (i == 0 || j == 0) {
				p[i][j] = i + j;
			} else {
				if (i > j) {
					p[i][j] = p[i - j][j];
				} else {
					p[i][j] = p[i][j - i];
				}
			}
		}
	}
	cin >> n >> m;
	long long res = 0;
	for (int x1 = 0; x1 < 2; ++x1) {
		for (int y1 = 0; y1 < 2; ++y1) {
			for (int x2 = 0; x2 < 2; ++x2) {
				for (int y2 = 0; y2 < 2; ++y2) {
					for (int x3 = 0; x3 < 2; ++x3) {
						for (int y3 = 0; y3 < 2; ++y3) {
							int s = gcd(x1 + x2, y1 + y2) + gcd(x2 + x3, y2 + y3) + gcd(x1 + x3, y1 + y3);
							if (s % 2 == 0) {
								long long A = get(n, x1) * get(m, y1);
								long long B = get(n, x2) * get(m, y2);
								long long C = get(n, x3) * get(m, y3);
								res += ((A * B) % P) * C;
								res %= P;
							}
						}
					}
				}
			}
		}
	}
	res -= (long long)(n + 1) * (long long)(m + 1);
	res = ((res % P) + P) % P;
	res -= 6LL * cnk2((n + 1) * (m + 1));
	res = ((res % P) + P) % P;
	for (int dx = 1; dx <= n; ++dx) {
		for (int dy = 1; dy <= m; ++dy) {
			if (dx == 0 && dy <= 0) {
				continue;
			}
			int k = p[dx][dy] - 1;
			ways[k] += (n - dx + 1) * (m - dy + 1);
			if (ways[k] >= P) {
				ways[k] -= P;
			}
		}
	}
	for (int i = 1; i < maxN; ++i) {
		res -= 12LL * (long long)(i) * (long long)(ways[i]);
		res %= P;
	}

	memset(ways, 0, sizeof(ways));
	for (int dx = 0; dx <= n; ++dx) {
		int l = 1, r = m;
		if (dx > 0) {
			l = 0;
			r = 0;
		}
		for (int dy = l; dy <= r; ++dy) {
			if (dx == 0 && dy <= 0) {
				continue;
			}
			int k = p[dx][dy] - 1;
			ways[k] += (n - dx + 1) * (m - dy + 1);
			if (ways[k] >= P) {
				ways[k] -= P;
			}
		}
	}

	for (int i = 1; i < maxN; ++i) {
		res -= 6LL * (long long)(i) * (long long)(ways[i]);
		res %= P;
	}

	res = ((res % P) + P) % P;
	cout << res << endl;

	return 0;
}