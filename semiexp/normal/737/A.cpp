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

int N, K;
i64 S, T;
i64 C[202020], V[202020];
i64 G[202020];

int main()
{
	scanf("%d%d%lld%lld", &N, &K, &S, &T);
	for (int i = 0; i < N; ++i) scanf("%lld%lld", C + i, V + i);
	for (int i = 1; i <= K; ++i) scanf("%lld", G + i);
	G[0] = 0;
	G[K + 1] = S;
	sort(G, G + (K + 2));
	vector<i64> L;
	for (int i = 1; i <= K + 1; ++i) L.push_back(G[i] - G[i - 1]);
	sort(L.begin(), L.end());

	vector<i64> Ls(L.size() + 1, 0LL);
	for (int i = L.size() - 1; i >= 0; --i) {
		Ls[i] = L[i] + Ls[i + 1];
	}

	i64 ret = 1LL << 60LL;
	T -= S;
	for (int i = 0; i < N; ++i) {
		if (L[L.size() - 1] > V[i]) {
			continue;
		}
		int rp = lower_bound(L.begin(), L.end(), (V[i] + 1) / 2) - L.begin();
		i64 c = 2 * Ls[rp] - V[i] * (L.size() - rp);
	//	printf("%d %d %lld\n", i, rp, c);

		if (c <= T) {
			ret = min(ret, C[i]);
		}
	}

	if (ret == (1LL << 60LL)) {
		ret = -1;
	}
	printf("%lld\n", ret);

	return 0;
}