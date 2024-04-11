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

int N, M;

int uf[1010101];
int deg[1010101], nonself, self;
bool waf[1010101];

int root(int p)
{
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}
bool join(int p, int q)
{
	p = root(p);
	q = root(q);

	if (p == q) return false;

	if (uf[p] > uf[q]) swap(p, q);
	uf[p] += uf[q];
	uf[q] = p;
	return true;
}

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; ++i) uf[i] = -1;

	int con = N;
	for (int i = 0; i < N; ++i) deg[i] = 0;
	nonself = 0;
	self = 0;

	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;

		if (join(u, v)) --con;

		if (u == v) {
			++self;
		} else {
			++nonself;
			++deg[u];
			++deg[v];
		}
		waf[u] = waf[v] = true;
	}

	for (int i = 0; i < N; ++i) if (!waf[i]) --con;

	if (con != 1) {
		puts("0");
		return 0;
	}

	i64 ret = 0;
	ret += (i64)self * (self - 1) / 2;
	ret += (i64)self * nonself;
	for (int i = 0; i < N; ++i) ret += (i64)deg[i] * (deg[i] - 1) / 2;
	printf("%lld\n", ret);


	return 0;
}