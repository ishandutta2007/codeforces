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

int N, A[202020], B[202020];

int uf[404040];

int root(int p) {
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}

bool join(int p, int q) {
	p = root(p);
	q = root(q);
	if (p == q) return false;
	if (p > q) swap(p, q);
	uf[p] += uf[q];
	uf[q] = p;
	return true;
}

void diffside(int p, int q) {
	// printf("%d %d diff\n", p, q);
	join(p * 2, q * 2 + 1);
	join(p * 2 + 1, q * 2);
}
void sameside(int p, int q) {
	// printf("%d %d same\n", p, q);
	join(p * 2, q * 2);
	join(p * 2 + 1, q * 2 + 1);
}

bool flipped[202020];
vector<pair<pair<int, int>, bool>> pts;

void apply(int lo, int hi) {
	if (hi - lo <= 1) return;

	int mid = (lo + hi) / 2;

	{
		int hir = -1;
		int hirp = -1;
		for (int i = mid; i < hi; ++i) {
			hir = max(hir, pts[i].first.second);
			if (hir == pts[i].first.second) hirp = i;
		}
		int lol = -1;
		for (int i = lo; i < mid; ++i) {
			if (pts[i].first.second < hir) {
				diffside(hirp, i);
				if (lol != -1) sameside(lol, i);
				lol = i;
			}
		}
		// printf("%d %d: %d\n", lo, hi, hir);
	}
	{
		int lol = N * 2;
		int lolp = -1;
		for (int i = lo; i < mid; ++i) {
			lol = min(lol, pts[i].first.second);
			if (lol == pts[i].first.second) lolp = i;
		}
		int hir = -1;
		for (int i = mid; i < hi; ++i) {
			if (pts[i].first.second > lol) {
				diffside(lolp, i);
				if (hir != -1) sameside(hir, i);
				hir = i;
			}
		}
		// printf("%d %d: %d\n", lo, hi, lol);
	}
	apply(lo, mid);
	apply(mid, hi);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", A + i, B + i);
		--A[i]; --B[i];
	}
	for (int i = 0; i < 2 * N; ++i) uf[i] = -1;

	int min_gt = 2 * N, max_lt = -1;
	for (int i = 0; i < N; ++i) {
		min_gt = min(min_gt, max(A[i], B[i]));
		max_lt = max(max_lt, min(A[i], B[i]));
	}
	if (min_gt < max_lt) {
		puts("-1");
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		if (A[i] > B[i]) {
			pts.push_back({{B[i], A[i]}, true});
		} else {
			pts.push_back({{A[i], B[i]}, false});
		}
	}
	sort(pts.begin(), pts.end());
	// for (int i = 0; i < N; ++i) printf("%d %d\n", pts[i].first.first, pts[i].first.second);
	apply(0, N);

	vector<int> wa(2 * N, 0);
	for (int i = 0; i < N; ++i) {
		if (root(i * 2) == root(i * 2 + 1)) {
			puts("-1");
			return 0;
		}
		int rt = root(i * 2);
		if (pts[i].second) {
			wa[rt]++;
		} else {
			wa[rt ^ 1]++;
		}
	}
	int ret = 0;
	for (int i = 0; i < N; ++i) ret += min(wa[i * 2], wa[i * 2 + 1]);
	printf("%d\n", ret);

	return 0;
}