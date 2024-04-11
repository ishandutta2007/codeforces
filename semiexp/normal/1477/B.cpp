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

struct segtree {
	static const int DEPTH = 18;
	static const int SIZE = 1 << DEPTH;

	segtree() {
		for (int i = 0; i < 2 * SIZE; ++i) {
			sum[i] = 0;
			prop[i] = -1;
		}
	}

	void update(int p, int lq, int rq, int val, int depth) {
		int lp = p << depth, rp = (p + 1) << depth;
		if (rq <= lp || rp <= lq) return;
		if (lq <= lp && rp <= rq) {
			//printf("upd %d %d\n", p, val);
			prop[p] = val;
			sum[p] = val << depth;
			return;
		}
		propagate(p);
		update(p * 2, lq, rq, val, depth - 1);
		update(p * 2 + 1, lq, rq, val, depth - 1);
		sum[p] = sum[p * 2] + sum[p * 2 + 1];
	}

	void propagate(int p) {
		if (prop[p] == -1) return;
		if (p < SIZE) {
			prop[p * 2] = prop[p * 2 + 1] = prop[p];
			sum[p * 2] = sum[p * 2 + 1] = sum[p] / 2;
			prop[p] = -1;
		}
	}

	void update(int lq, int rq, int val) {
		update(1, lq + SIZE, rq + SIZE, val, DEPTH);
	}

	int query(int p, int lq, int rq, int depth) {
		int lp = p << depth, rp = (p + 1) << depth;
		//printf("%d %d %d %d %d %d\n", p, lq, rq, lp, rp, depth);
		if (rq <= lp || rp <= lq) return 0;
		if (lq <= lp && rp <= rq) {
			//printf("q %d %d\n", p, sum[p]);
			return sum[p];
		}
		propagate(p);
		return query(p * 2, lq, rq, depth - 1) + query(p * 2 + 1, lq, rq, depth - 1);
	}

	int query(int lq, int rq) {
		return query(1, lq + SIZE, rq + SIZE, DEPTH);
	}

	int sum[2 * SIZE], prop[2 * SIZE];
};

int TC;
int N, Q;
char S[202020], T[202020];
int L[202020], R[202020];

segtree seg;

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d%d%s%s", &N, &Q, S, T);
		for (int i = 0; i < Q; ++i) {
			scanf("%d%d", L + i, R + i);
			--L[i];
		}

		for (int i = 0; i < N; ++i) {
			seg.update(i, i + 1, T[i] - '0');
		}

		for (int i = Q - 1; i >= 0; --i) {
			int sz = R[i] - L[i];
			int sum = seg.query(L[i], R[i]);

			//printf("%d %d\n", sz, sum);
			int target;
			if (sum * 2 == sz) {
				goto fail;
			} else if (sum * 2 < sz) {
				target = 0;
			} else {
				target = 1;
			}
			seg.update(L[i], R[i], target);
		}
		for (int i = 0; i < N; ++i) {
			int a = seg.query(i, i + 1);
			//printf("%d: %d\n", i, a);
			if (a != S[i] - '0') goto fail;
		}
		puts("YES");
		continue;

	fail:
		puts("NO");
	}
	return 0;
}