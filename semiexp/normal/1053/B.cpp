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
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
i64 A[302020];
int cnt[303030];
int par[303030];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld", A + i);

	par[0] = 0;
	for (int i = 1; i <= N; ++i) {
		cnt[i - 1] = __builtin_popcountll(A[i - 1]);
		par[i] = par[i - 1] ^ (cnt[i - 1] & 1);
	}

	i64 n0 = 0, n1 = 0;
	for (int i = 0; i <= N; ++i) {
		//printf("%d\n", par[i]);
		if (par[i] == 0) ++n0;
		else ++n1;
	}

	i64 ans = n0 * (n0 - 1) / 2 + n1 * (n1 - 1) / 2;
	for (int i = 0; i < N; ++i) {
		int s = 0, mx = 0;
		for (int j = i; j < N; ++j) {
			s += cnt[j];
			mx = max(mx, cnt[j]);
			if (s % 2 == 0 && mx > s / 2) --ans;
			if (s > 124) break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}