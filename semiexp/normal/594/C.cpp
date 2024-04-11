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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, K;
i64 mx[101010], my[101010];

vector<pair<i64, int> > xs, ys;

i64 test(int lx, int hx, int ly, int hy)
{
	if (lx + hx > K || ly + hy > K) return 1LL << 62LL;

	set<int> taken;
	for (int i = 0; i < lx; ++i) {
		taken.insert(xs[i].second);
	}
	for (int i = 0; i < hx; ++i) {
		taken.insert(xs[xs.size() - i - 1].second);
	}
	for (int i = 0; i < ly; ++i) {
		taken.insert(ys[i].second);
	}
	for (int i = 0; i < hy; ++i) {
		taken.insert(ys[ys.size() - i - 1].second);
	}
	if (taken.size() > K) return 1LL << 62LL;

	//printf("%d %d %d %d\n", lx, hx, ly, hy);
	return ((max(1LL, xs[xs.size() - 1 - hx].first - xs[lx].first) + 1) / 2) * ((max(1LL, ys[ys.size() - 1 - hy].first - ys[ly].first) + 1) / 2);
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		mx[i] = x1 + x2;
		my[i] = y1 + y2;

		xs.push_back({ mx[i], i });
		ys.push_back({ my[i], i });
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	i64 ret = 1LL << 62LL;
	for (int a = 0; a <= K; ++a) {
		for (int b = 0; b <= K; ++b) {
			for (int c = 0; c <= K; ++c) {
				for (int d = 0; d <= K; ++d) {
					ret = min(ret, test(a, b, c, d));
				}
			}
		}
	}
	cout << ret << endl;

	return 0;
}