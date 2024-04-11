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
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

template <int M>
struct segtree {
	static const int DEPTH = 18;
	static const int N = 1 << DEPTH;
	i64 data[2 * N];

	segtree() {
		fill(data, data + 2 * N, 0);
	}

	void update(int p, i64 v) {
		p += N;
		if (M == 0) data[p] = v;
		else data[p] = v % M;
		p >>= 1;
		while (p) {
			if (M == 0) data[p] = data[p * 2] + data[p * 2 + 1];
			else data[p] = (data[p * 2] + data[p * 2 + 1]) % M;
			p >>= 1;
		}
	}

	i64 query(int L, int R) {
		L += N;
		R += N;
		i64 ret = 0;
		while (L < R) {
			if (L & 1) ret += data[L++];
			if (R & 1) ret += data[--R];
			L >>= 1;
			R >>= 1;
		}
		if (M != 0) ret %= M;
		return ret;
	}
};

int N, Q;
i64 A[202020], W[202020];

segtree<0> seg1;
segtree<MOD> seg2;

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) scanf("%lld", A + i);
	for (int i = 0; i < N; ++i) scanf("%lld", W + i);

	for (int i = 0; i < N; ++i) {
		A[i] -= i;
		seg1.update(i, W[i]);
		seg2.update(i, A[i] * W[i]);
	}

	for (;Q--;) {
		int x, y;
		scanf("%d%d", &x, &y);

		if (x < 0) {
			int id = -x - 1;
			int nw = y;
			// TODO
			W[id] = nw;
			seg1.update(id, W[id]);
			seg2.update(id, A[id] * W[id]);
			continue;
		}

		int l = x - 1;
		int r = y;

		i64 tw = seg1.query(l, r);
		int left = l, right = r;
		while (left < right) {
			int mid = (left + right) / 2;
			if (seg1.query(l, mid) * 2 >= tw) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}

		int ctr = left - 1;
		// printf("%d %d: %d\n", l, r, ctr);
		i64 ans = MOD * 2 + seg1.query(l, ctr + 1) % MOD * A[ctr] % MOD - seg2.query(l, ctr + 1) + seg2.query(ctr + 1, r) - seg1.query(ctr + 1, r) % MOD * A[ctr] % MOD;
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}