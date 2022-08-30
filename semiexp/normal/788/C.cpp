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
#include <bitset>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, K;
bool oks[1010];

int main()
{
	scanf("%d%d", &N, &K);
	int lo = 1000, hi = 0;
	for (int i = 0; i < K; ++i) {
		int a;
		scanf("%d", &a);
		oks[a] = true;

		lo = min(lo, a); hi = max(hi, a);
	}
	if (!(lo <= N && N <= hi)) {
		puts("-1");
		return 0;
	}

	int sd[2020];
	for (int i = 0; i <= 2000; ++i) sd[i] = 100000;

	int ofs = 1000;
	queue<int> Q;
	for (int i = 0; i <= 1000; ++i) if (oks[i]) {
		sd[i - N + ofs] = 1;
		Q.push(i - N + ofs);
	}

	while (!Q.empty()) {
		int p = Q.front(); Q.pop();
		for (int i = 0; i <= 1000; ++i) if (oks[i]) {
			int q = p + i - N;
			if (0 <= q && q <= 2000 && sd[q] > 10000) {
				   sd[q] = sd[p] + 1;
				Q.push(q);
			}
		}
	}
	printf("%d\n", sd[ofs]);

	return 0;
}