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

int N;
pair<i64, i64> city[101010];
i64 dp[101010];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		i64 a, c;
		scanf("%lld%lld", &a, &c);
		city[i] = make_pair(a, a + c);
	}
	sort(city, city + N);

	dp[0] = 0;
	set<pair<i64, i64>> flat;
	i64 min_coef = 1LL << 60LL;

	flat.insert({0LL, city[0].second});

	for (int i = 1; i < N; ++i) {
		while (!flat.empty() && flat.begin()->second < city[i].first) {
			min_coef = min(min_coef, flat.begin()->first - flat.begin()->second);
			flat.erase(flat.begin());
		}

		i64 best = min_coef + city[i].first;
		if (!flat.empty()) best = min(best, flat.begin()->first);
		flat.insert({best, city[i].second});
		dp[i] = best;
	}

	i64 ans = dp[N - 1];
	for (int i = 0; i < N; ++i) ans += city[i].second - city[i].first;
	printf("%lld\n", ans);

	return 0;
}