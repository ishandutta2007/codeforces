#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int uf[100100]; 

int N, M;
vector<int> G[1000100];
int X[100100];
ivec ret;

int root(int p)
{
	return (uf[p] < 0 ? p : (uf[p] = root(uf[p])));
}

void join(int p, int q)
{
	p = root(p); q = root(q);

	if (p == q) return;

	uf[p] += uf[q];
	uf[q] = p;
}

void resolve(int p, int rt)
{
	X[p] ^= 1;
	ret.push_back(p);

	for (int i = 0; i < G[p].size(); i++) {
		int p2 = G[p][i];
		if (p2 == rt) continue;

		if (G[p2].size() == 1 && X[p2] == 0) continue;

		resolve(p2, p);

		ret.push_back(p);
		X[p] ^= 1;

		if (X[p2] == 1) {
			ret.push_back(p2);
			ret.push_back(p);
			X[p] ^= 1;
			X[p2] ^= 1;
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) uf[i] = -1;

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;

		if (root(u) != root(v)) {
			join(u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}

	int bp = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d", X + i);

		if (X[i] == 1) bp = i;
	}

	if (bp == -1) {
		puts("0");
		return 0;
	}

	for (int i = 0; i < N; i++) if (X[i] && root(i) != root(bp)) {
		puts("-1");
		return 0;
	}

	resolve(bp, -1);

	if (X[bp]) ret.pop_back();

	printf("%d\n%d", ret.size(), ret[0] + 1);
	for (int i = 1; i < ret.size(); i++) {
		printf(" %d", ret[i] + 1);
	}
	puts("");

	return 0;
}