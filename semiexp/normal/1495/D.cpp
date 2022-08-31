#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 998244353
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M;
vector<int> graph[440];
int wf[440][440];
i64 ans[440][440];

int myabs(int x) {
	return max(x, -x);
}

int toward[440][440]; // t[x][y]: x -> y

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			wf[i][j] = (i == j) ? 0 : 1000000;
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		wf[x][y] = wf[y][x] = 1;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				wf[j][k] = min(wf[j][k], wf[j][i] + wf[i][k]);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int t = 0;
			for (int k = 0; k < N; ++k) {
				if (wf[i][k] == 1 && wf[j][k] == wf[i][j] - 1) ++t;
			}
			toward[i][j] = t;
		}
	}

	int dc[440];
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			// if (x != 0 || y != 2) continue;
			bool flg = true;
			for (int i = 0; i <= N; ++i) dc[i] = -1;
			i64 res = 1;

			for (int z = 0; z < N; ++z) {
				if (wf[x][z] + wf[y][z] == wf[x][y]) {
					int d = wf[x][z];
					if (dc[d] == -1) dc[d] = z;
					else dc[d] = -2;
				}
			}

			for (int i = 0; i <= wf[x][y]; ++i) {
				if (dc[i] < 0) flg = false;
			}

			if (!flg) {
				ans[x][y] = 0;
				continue;
			}
			for (int z = 0; z < N; ++z) {
				int p = wf[z][x], q = wf[z][y];
				if ((p + q + wf[x][y]) % 2 != 0) {
					flg = false;
					break;
				}
				int d = (p + wf[x][y] - q) / 2;
				int base = dc[d];
				// printf("%d -> %d\n", z, base);
				if (wf[z][x] != wf[z][base] + wf[base][x]) {
					flg = false;
					break;
				}
				if (wf[z][y] != wf[z][base] + wf[base][y]) {
					flg = false;
					break;
				}
				if (z == base) continue;
				//printf("%d,%d %d->%d\n", x, y, z, base);
				res = res * toward[z][base] % MOD;
			}
			/*
			for (int z = 0; z < N; ++z) {
				if (z == x || z == y) continue;
				if (myabs(wf[x][z] - wf[y][z]) != wf[x][y]) {
					if (wf[x][z] + wf[y][z] == wf[x][y]) {
						++dc[wf[x][z]];
						int d = wf[x][z];
						if (dc[d] == -1) dc[d] = z;
						else dc[d] = -2;
					} else {
						flg = false;
					}
				} else {
					if (wf[x][z] - wf[y][z] == wf[x][y]) {
						res = res * toward[z][y] % MOD;
					} else {
						res = res * toward[z][x] % MOD;
					}
				}
			}
			for (int i = 1; i <= wf[x][y] - 1; ++i) {
				if (dc[i] != 1) flg = false;
			}
			*/
			if (flg) {
				ans[x][y] = res;
			} else {
				ans[x][y] = 0;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) printf("%lld%c", ans[i][j], j == N - 1 ? '\n' : ' ');
	}
	return 0;
}