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
i64 X[5050], Y[5050];
vector<int> ans;
bool visited[5050];

i64 dist(int i, int j) {
	return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld%lld", X + i, Y + i);
		visited[i] = false;
	}

	pair<i64, pair<int, int>> bp{-1, {0, 0}};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			bp = max(bp, {dist(i, j), {i, j}});
		}
	}
	int p = bp.second.first;
	int q = bp.second.second;
	ans.push_back(p); visited[p] = true;
	ans.push_back(q); visited[q] = true;
	for (int i = 0; i < N - 2; ++i) {
		pair<i64, int> bq{-1, -1};
		for (int j = 0; j < N; ++j) if (!visited[j]) {
			bq = max(bq, {dist(q, j), j});
		}
		int r = bq.second;
		ans.push_back(r);
		visited[r] = true;
		p = q;
		q = r;
	}
	for (int i = 0; i < N; ++i) printf("%d%c", ans[i] + 1, i == N - 1 ? '\n' : ' ');
	return 0;
}