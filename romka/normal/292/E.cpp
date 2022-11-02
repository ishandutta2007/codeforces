#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 200010;

int n, m, a[maxn], b[maxn], x[maxn], y[maxn], k;

struct SegmentTreeSum {
	vector<int> add;
	int N;

	SegmentTreeSum(int n) {
		for (N = 1; N < n; N <<= 1);
		add.resize(N * 2, -1);
	}

	void init(int n) {
		for (N = 1; N < n; N <<= 1);
		add.assign(N * 2, -1);	
	}

	void modify(int l, int r, int d) {
		modify(1, 0, N-1, l, r, d);
	}

	int get(int x) {
		return get(1, 0, N-1, x);
	}

	void push(int i) {
		if (add[i] == -1) return;
		if (i < N)
			add[i * 2] = add[i * 2 + 1] = add[i];
		add[i] = -1;
	}

	void modify(int i, int L, int R, int qL, int qR, int d) {
		if (L == qL && R == qR) {
			add[i] = d;
		} else {
			push(i);
			int M = (L + R) >> 1;
			if (qL <= M) modify(i * 2, L, M, qL, min(M, qR), d);
			if (qR > M) modify(i * 2 + 1, M+1, R, max(qL, M+1), qR, d);
		}
	}

	int get(int i, int L, int R, int x) {
		if (add[i] != -1) {
			return add[i];
		} else {
			if (L == R) return -1;
			int M = (L + R) >> 1;
			if (x <= M) return get(i * 2, L, M, x);
			else return get(i * 2 + 1, M + 1, R, x);
		}
	}
};

SegmentTreeSum tree(0);

int main() {
	scanf("%d %d", &n, &m);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, n) scanf("%d", &b[i]);

	tree.init(n);

	int t, z;
	forn(i, m) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d %d", &x[i], &y[i], &k);
			x[i]--, y[i]--;
			tree.modify(y[i], y[i] + k - 1, i);
		} else {
			scanf("%d", &z);
			z--;
			int ind = tree.get(z);
			if (ind == -1) printf("%d\n", b[z]);
			else printf("%d\n", a[x[ind] + (z - y[ind])]);
		}
	}

	return 0;
}