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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
const int maxN = 55;
int n, k;
int a, b;

long long d[4 * maxN][maxN][maxN];
bool can[4 * maxN][maxN][maxN];
long long c[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1LL;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
		}
	}

	cin >> n >> k;
	a = b = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v == 50) {
			++a;
		} else {
			++b;
		}
	}
	k = (k - (k % 50)) / 50;

	d[0][a][b] = 1;
	can[0][a][b] = true;
	for (int step = 0; step < 4 * maxN; ++step) {
		if (step % 2 == 1 && can[step][a][b]) {
			printf("%d\n%I64d\n", step, d[step][a][b]);
			return 0;
		}
		int side = (step % 2 == 0 ? 0 : 1);
		for (int x = 0; x <= a; ++x) {
			for (int y = 0; y <= b; ++y) {
				if (!can[step][x][y]) {
					continue;
				}

				for (int v = 0; v <= y && v + v <= k; ++v) {
					for (int u = 0; u <= x && u <= k - 2 * v; ++u) {
						if (u == 0 && v == 0) {
							continue;
						}
						long long ways = (c[y][v] * c[x][u]) % P;
						int nx = a - x + u;
						int ny = b - y + v;
						d[step + 1][nx][ny] += ways * d[step][x][y];
						d[step + 1][nx][ny] %= P;
						can[step + 1][nx][ny] = true;
					}
				}
			}
		}
	}
	printf("-1\n0\n");


	return 0;
}