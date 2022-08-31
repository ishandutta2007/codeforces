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

int N; i64 A, Cf, Cm; i64 M;
i64 Ai[101010];

i64 B[101010];
i64 tot[101010];

int main()
{
	scanf("%d%lld%lld%lld%lld", &N, &A, &Cf, &Cm, &M);
	for (int i = 0; i < N; ++i) scanf("%lld", Ai + i);

	for (int i = 0; i < N; ++i) B[i] = Ai[i];
	sort(B, B + N);
	B[N] = A + 1;

	tot[0] = 0;
	for (int i = 0; i < N; ++i) tot[i + 1] = tot[i] + B[i];

	i64 req = 0;
	pair<i64, pair<int, i64> > best{ -1, {-1, -1} };

	for (int i = 0; i <= N; ++i) {
		// i: number of perfect skills
		i64 rem = M - req;
		if (rem < 0) break;

		int left = 0, right = N - i;
		while (left < right) {
			i64 mid = (left + right + 1) / 2;
			if ((i64)mid * B[mid - 1] - tot[mid] <= rem) left = mid;
			else right = mid - 1;
		}

		i64 lo = (left == 0 ? A : ((rem - (i64)left * B[left - 1] + tot[left]) / left + B[left - 1]));
	//	printf("%d %d %lld\n", i, left, lo);
		lo = min(lo, (i64)A);

		i64 sco = Cf * i + Cm * lo;
		best = max(best, { sco, {i, lo} });

		req += A - B[N - i - 1];
	}

	vector<pair<i64, int> > sorter;
	for (int i = 0; i < N; ++i) sorter.push_back({ Ai[i], i });
	sort(sorter.begin(), sorter.end());
	reverse(sorter.begin(), sorter.end());
	for (int i = 0; i < best.second.first; ++i) {
		Ai[sorter[i].second] = A;
	}

	printf("%lld\n", best.first);
	//printf("%d %lld\n", best.second.first, best.second.second);
	for (int i = 0; i < N; ++i) {
		i64 cur = max(Ai[i], best.second.second);
		printf("%lld%c", cur, i == N - 1 ? '\n' : ' ');
	}
	return 0;
}