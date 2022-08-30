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

int N, M, Wmax;
int W[1010], B[1010];
int uf[1010];

int root(int p)
{
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}
void join(int p, int q)
{
	p = root(p);
	q = root(q);
	if (p == q) return;
	uf[p] += uf[q];
	uf[q] = p;
}

vector<int> grp[1010];
vector<int> dp;

vector<int> upd(vector<int> &V, int W, int B)
{
	vector<int> ret = V;
	for (int i = ret.size() - 1; i >= W; --i) {
		ret[i] = max(ret[i], ret[i - W] + B);
	}
	return ret;
}

int main()
{
	scanf("%d%d%d", &N, &M, &Wmax);
	for (int i = 0; i < N; ++i) scanf("%d", W + i);
	for (int i = 0; i < N; ++i) scanf("%d", B + i);
	for (int i = 0; i < N; ++i) uf[i] = -1;
	
	for (int i = 0; i < M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		join(x - 1, y - 1);
	}

	for (int i = 0; i < N; ++i) {
		grp[root(i)].push_back(i);
	}

	dp = vector<int>(Wmax + 1, 0);
	for (int i = 0; i < N; ++i) if (grp[i].size() > 0) {
		vector<vector<int> > tmp;
		int sw = 0, sb = 0;
		for (int g : grp[i]) {
			sw += W[g];
			sb += B[g];
			tmp.push_back(upd(dp, W[g], B[g]));
		}
		tmp.push_back(upd(dp, sw, sb));
		for (vector<int> &v : tmp) {
			for (int j = 0; j < dp.size(); ++j) dp[j] = max(dp[j], v[j]);
		}
	}
	int ret = 0;
	for (int v : dp) ret = max(ret, v);
	printf("%d\n", ret);

	return 0;
}