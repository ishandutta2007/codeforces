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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M, Q;
int X[505050], Y[505050], W[505050];
int U[505050], V[505050], L[505050];

bool isok[505050];

i64 sd[660][660];
vector<pair<int, int>> adj[660];
i64 tu[660];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int x, y, l;
		scanf("%d%d%d", &x, &y, &l);
		--x; --y;
		X[i] = x; Y[i] = y; W[i] = l;
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		scanf("%d%d%d", U + i, V + i, L + i);
		--U[i]; --V[i];
		adj[U[i]].push_back({V[i], L[i]});
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) sd[i][j] = (i == j) ? 0 : (1LL << 60LL);
	for (int i = 0; i < M; ++i) {
		sd[X[i]][Y[i]] = min(sd[X[i]][Y[i]], (i64)W[i]);
		sd[Y[i]][X[i]] = sd[X[i]][Y[i]];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				sd[j][k] = min(sd[j][k], sd[j][i] + sd[i][k]);
			}
		}
	}

	for (int i = 0; i < M; ++i) isok[i] = false;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			tu[j] = 1LL << 60LL;
			for (auto a : adj[i]) {
				tu[j] = min(tu[j], sd[j][a.first] - a.second);
			}
		}
		for (int e = 0; e < M; ++e) {
			int x = X[e], y = Y[e], w = W[e];
			if (sd[i][x] + tu[y] + w <= 0 || sd[i][y] + tu[x] + w <= 0) isok[e] = true;
		}
	}

	int ret = 0;
	for (int i = 0; i < M; ++i) if (isok[i]) ++ret;
	printf("%d\n", ret);

	return 0;
}