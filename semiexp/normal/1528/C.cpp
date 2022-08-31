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

int N, A[303030], B[303030];
vector<int> chA[303030], chB[303030];
int lf[303030], rg[303030], pt;
int bel[606060];

void etour(int p) {
	bel[pt] = p;
	lf[p] = pt++;
	for (int q : chB[p]) etour(q);
	bel[pt] = p;
	rg[p] = ++pt;
}

struct segtree {
	void init(int N) {
		depth = 1;
		while ((1 << depth) < N) ++depth;

		rm.resize(2 << depth);
		sz = 1 << depth;

		for (int i = 0; i < sz; ++i) rm[i + sz] = -1; //i;
		for (int i = sz - 1; i > 0; --i) rm[i] = max(rm[i * 2], rm[i * 2 + 1]);
	}

	void mask(int p, int qL, int qR, bool ki, int d) {
		int pL = (p << d), pR = (p + 1) << d;
		if (qR <= pL || pR <= qL) return;
		if (qL <= pL && pR <= qR) {
			if (ki) {
				rm[p] = -1;
			} else {
				if (d == 0) rm[p] = p - sz;
				else rm[p] = max(rm[p * 2], rm[p * 2 + 1]);
			}
			//printf("m %d %d %d %d %d -> %d\n", p, qL, qR, ki, d, rm[p]);
			return;
		}
		mask(p * 2, qL, qR, ki, d - 1);
		mask(p * 2 + 1, qL, qR, ki, d - 1);
		rm[p] = max(rm[p * 2], rm[p * 2 + 1]);
		//printf("m %d %d %d %d %d -> %d\n", p, qL, qR, ki, d, rm[p]);
	}

	void mask(int qL, int qR, bool ki) {
		mask(1, qL + sz, qR + sz, ki, depth);
	}

	int query(int p, int qL, int qR, int d) {
		int pL = (p << d), pR = (p + 1) << d;
		//printf("a %d %d %d %d\n", p, qL, qR, d);
		if (qR <= pL || pR <= qL) return -1;
		if (qL <= pL && pR <= qR) {
			//printf("%d--%d: %d\n", pL - sz, pR - sz, rm[p]);
			return rm[p];
		}
		if (rm[p] == -1) return -1;
		int ans = max(query(p * 2, qL, qR, d - 1), query(p * 2 + 1, qL, qR, d - 1));
		return ans;
	}

	int query(int qL, int qR) {
		return query(1, qL + sz, qR + sz, depth);
	}

	int depth, sz;
	vector<int> rm;
};

segtree seg;
int ans, cur;
bool alive[303030];

void dfs(int p) {
	int victim = -1;
	// printf("%d: %d %d\n", p, lf[p], rg[p]);
	if (p > 0) {
		int r = seg.query(0, lf[p]);
		if (r != -1) {
			if (bel[r] == -1) throw 5;
			r = bel[r];
			if (lf[r] < lf[p] && rg[p] < rg[r]) {
				victim = r;
			}
		}
	}
	if (false) {
		int v2 = -1;
		for (int i = B[p]; i >= 0; i = B[i]) {
			if (alive[i]) {
				v2 = i;
				break;
			}
		}
		if (victim != v2) {
			printf("%d %d %d\n", p, victim, v2);
			throw 2;
		}
	}

	if (victim != -1) {
		//printf("%d <- %d\n", p, victim);
		seg.mask(lf[victim], lf[victim] + 1, true);
		--cur;
		alive[victim] = false;
	}
	seg.mask(lf[p], lf[p] + 1, false);
	alive[p] = true;
	++cur;

	ans = max(ans, cur);

	for (int q : chA[p]) dfs(q);

	seg.mask(lf[p], lf[p] + 1, true);
	alive[p] = false;
	--cur;
	if (victim != -1) {
		seg.mask(lf[victim], lf[victim] + 1, false);
		++cur;
		alive[victim] = true;
	}
}

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d", &N);
		for (int i = 1; i < N; ++i) {
			scanf("%d", A + i);
			--A[i];
		}
		for (int j = 1; j < N; ++j) {
			scanf("%d", B + j);
			--B[j];
		}
		B[0] = -1;
		for (int i = 0; i < N; ++i) {
			chA[i].clear();
			chB[i].clear();
		}
		for (int i = 1; i < N; ++i) {
			chA[A[i]].push_back(i);
			chB[B[i]].push_back(i);
		}
		for (int i = 0; i < 2 * N; ++i) bel[i] = -1;

		pt = 0;
		etour(0);

		seg.init(2 * N);

		ans = 0;
		cur = 0;
		dfs(0);

		printf("%d\n", ans);
	}

	return 0;
}