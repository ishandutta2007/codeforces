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

const int INFT = 100100100;

int N;
i64 A[101010];
vector<pair<i64, int>> sorted;
int dp[65][101010];

vector<pair<i64, int>> compute_sorted(int b)
{
	// TODO
	vector<pair<i64, int>> ret;
	ret.push_back({0LL, -1});
	for (int i = 0; i < N; ++i) {
		i64 x = A[i] ^ ((A[i] >> b) << b);
		ret.push_back({x, i});
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int count_at_most(vector<pair<i64, int>> &seq, i64 v)
{
	return upper_bound(seq.begin(), seq.end(), make_pair(v, 101010)) - seq.begin();
}

int naive()
{
	int ret = INFT;
	i64 lo = 0;
	for (int i = 0; i < N; ++i) lo = max(lo, A[i]);

	for (int i = lo; i <= 3000; ++i) {
		int x = 0;
		for (int j = 0; j < N; ++j) {
			x += __builtin_popcount(i - (int)A[j]);
		}
		ret = min(ret, x);
	}
	return ret;
}
int getret(int layer)
{
	int ret = INFT;
	for (int i = 0; i <= N; ++i) {
		ret = min(ret, dp[layer][i]);
	}
	ret = dp[layer][N];
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%lld", A + i);

	vector<pair<i64, int>> sorted, sorted_next = compute_sorted(0);
	for (int i = 0; i <= N; ++i) dp[0][i] = 0;
	for (int j = 1; j <= 62; ++j) {
		for (int i = 0; i <= N; ++i) dp[j][i] = INFT;
	}
	for (int b = 0; b < 62; ++b) {
		swap(sorted, sorted_next);
		sorted_next = compute_sorted(b + 1);

		for (int i = 0; i <= N; ++i) {
			int aug1 = count_at_most(sorted_next, sorted[i].first + (1LL << (i64)b)) - count_at_most(sorted_next, sorted[i].first);
			{
				i64 v = sorted[i].first;
				int sco = dp[b][i] + aug1;
				int idx = upper_bound(sorted_next.begin(), sorted_next.end(), make_pair(v, 101010)) - sorted_next.begin() - 1;
				//printf("%d %d: %d\n", b, i, idx);
				dp[b + 1][idx] = min(dp[b + 1][idx], sco);
			}
			{
				i64 v = sorted[i].first + (1LL << (i64)b);
				int sco = dp[b][i] + (N - aug1);
				int idx = upper_bound(sorted_next.begin(), sorted_next.end(), make_pair(v, 101010)) - sorted_next.begin() - 1;
				dp[b + 1][idx] = min(dp[b + 1][idx], sco);
			}
		}
		//for (int i = 0; i <= N; ++i) printf("%d ", dp[b][i]); puts("");
	}
	int ret = getret(59);
	int na = ret; //naive();
	printf("%d\n", ret);
	if (ret != na) {
		printf("%d %d\n", ret, na);
		for (int i = 0; i < N; ++i) printf("%d ", (int)A[i]); puts("");
	}
	return 0;
}