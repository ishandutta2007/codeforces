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

int N, H[303030], B[303030];
int rb[19][303030];

i64 dp[303030];
vector<pair<i64, int>> eject[303030];

struct segtree {
	static const int DEPTH = 19;
	static const int N = 1 << DEPTH;

	segtree() {
		for (int i = 0; i < 2 * N; ++i) data[i] = -(1LL << 60LL);
	}

	void update(int p, i64 v) {
		p += N;
		while (p) {
			data[p] = max(data[p], v);
			p >>= 1;
		}
	}
	i64 query(int L, int R) {
		L += N; R += N;
		i64 ret = -(1LL << 60LL);
		while (L < R) {
			if (L & 1) ret = max(ret, data[L++]);
			if (R & 1) ret = max(ret, data[--R]);
			L >>= 1; R >>= 1;
		}
		return ret;
	}
	i64 data[2 * N];
};

segtree seg;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", H + i);
		--H[i];
	}
	for (int i = 0; i < N; ++i) scanf("%d", B + i);

	for (int i = 0; i < N; ++i) rb[0][i] = H[i];
	for (int i = 1; i <= 18; ++i) {
		for (int j = 0; j < N; ++j) {
			int j2 = j + (1 << (i - 1));
			rb[i][j] = min(rb[i - 1][j], j2 < N ? rb[i - 1][j2] : N);
		}
	}

	dp[0] = 0;
	seg.update(0, 0);
	set<pair<i64, int>> events;
	i64 ans = -(1LL << 60LL);

	for (int i = 0; i < N; ++i) {
		for (auto e : eject[i]) events.erase(e);
		int right = i + 1;
		for (int j = 18; j >= 0; --j) {
			if (rb[j][right] > H[i] && (right + (1 << j)) <= N) right += (1 << j);
		}
		int left = i;
		for (int j = 18; j >= 0; --j) {
			int l2 = left - (1 << j);
			if (l2 >= 0 && rb[j][l2] > H[i]) left = l2;
		}

		i64 tmp = seg.query(left, i + 1);
		if (!events.empty()) {
			tmp = max(tmp, (--events.end())->first);
		}
		tmp += B[i];
		dp[i + 1] = tmp;
		seg.update(i + 1, tmp);
		if (right == N) ans = max(ans, tmp);
		events.insert({tmp, i});
		eject[right].push_back({tmp, i});

		//printf("%d %d %d %lld\n", i, right, left, tmp);

	}

	printf("%lld\n", ans);
	return 0;
}