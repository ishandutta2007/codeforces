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
int N, M;
vector<int> K[101010];
int ans[101010];

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; ++i) {
			int l, x;
			scanf("%d", &l);
			K[i].clear();
			for (int j = 0; j < l; ++j) {
				scanf("%d", &x);
				K[i].push_back(--x);
			}
		}
		map<int, int> cnt;
		for (int i = 0; i < M; ++i) {
			if (K[i].size() == 1) {
				ans[i] = K[i][0];
				cnt[K[i][0]] += 1;
			} else ans[i] = -1;
		}
		int threshold = (M + 1) / 2 + 1;
		for (auto p : cnt) {
			if (p.second >= threshold) {
				goto fail;
			}
		}
		for (int i = 0; i < M; ++i) if (ans[i] == -1) {
			pair<int, int> best{1000000, -1};
			for (int j : K[i]) {
				best = min(best, {cnt[j], j});
			}
			cnt[best.second] += 1;
			ans[i] = best.second;
		}
		puts("YES");
		for (int i = 0; i < M; ++i) printf("%d%c", ans[i] + 1, i == M - 1 ? '\n' : ' ');
		continue;
	fail:
		puts("NO");
	}
	return 0;
}