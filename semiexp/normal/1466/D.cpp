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

int T;
int N;
i64 W[101010];
vector<int> tree[101010];
int deg[101010];

int main()
{
	scanf("%d", &T);
	for (;T--;) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%lld", W + i);
		for (int i = 0; i < N; ++i) tree[i].clear();

		for (int i = 0; i < N - 1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;

			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		for (int i = 0; i < N; ++i) deg[i] = tree[i].size();

		vector<i64> ans;
		vector<i64> decl;
		i64 sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += W[i] * deg[i];
			for (int j = 0; j < deg[i] - 1; ++j) decl.push_back(W[i]);
		}
		sort(decl.begin(), decl.end());

		ans.push_back(sum);
		for (int i = 0; i < decl.size(); ++i) {
			sum -= decl[i];
			ans.push_back(sum);
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < N - 1; ++i) printf("%lld%c", ans[i], i == N - 2 ? '\n' : ' ');
	}
	return 0;
}