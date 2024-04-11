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

int TC;

int N;
vector<int> A[202020];
int visited[202020];
int ans[202020];

int dfs(int p) {
	if (visited[p] == 2) return ans[p];
	else if (visited[p] == 1) return -1;

	visited[p] = 1;
	int ret = 1;
	for (int q : A[p]) {
		int x = dfs(q);
		if (x == -1) return -1;
		ret = max(ret, x + (p < q ? 1 : 0));
	}
	visited[p] = 2;
	return ans[p] = ret;
}

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			int k;
			scanf("%d", &k);
			A[i].clear();
			for (int j = 0; j < k; ++j) {
				int v;
				scanf("%d", &v);
				A[i].push_back(--v);
			}
		}
		for (int i = 0; i < N; ++i) {
			visited[i] = 0;
		}
		int ret = 0;
		for (int i = 0; i < N; ++i) {
			int p = dfs(i);
			if (p < 0) {
				ret = -1;
				break;
			} else {
				ret = max(ret, p);
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}