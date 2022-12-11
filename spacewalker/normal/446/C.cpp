#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = array<ll, 4>;

constexpr ll MOD = 1000000009;
constexpr int NMAX = 300010;
matrix M_ZERO, M_FIB, M_ID;

matrix geomSum[NMAX], geomPower[NMAX];

matrix operator + (matrix a, matrix b) {
	matrix ans = M_ZERO;
	for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) ans[i*2+j] = (a[i*2+j] + b[i*2+j]) % MOD;
	return ans;
}

matrix operator * (matrix a, matrix b) {
	matrix ans = M_ZERO;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				ans[i*2+j] = (ans[i*2+j] + a[i*2+k] * b[k*2+j]) % MOD;
			}
		}
	}
	return ans;
}

void dbgPrint(matrix a) {
//	printf("[[%lld %lld]\n [%lld %lld]]\n", a[0][0], a[0][1], a[1][0], a[1][1]);
}

struct DZYTree {
	int al, ar;
	matrix rsum, lazyft;
	DZYTree *left, *right;
	void combine() {
		rsum = left->rsum + right->rsum;
	}
	void propagate() {
		if (lazyft != M_ZERO) {
//			printf("lazy add\n");
//			dbgPrint(lazyft);
//			printf("adding this to range %d %d:\n", al, ar);
//			dbgPrint(geomSum[ar - al]);
//			printf("rsum now\n");
//			dbgPrint(rsum);
			rsum = rsum + lazyft * geomSum[ar - al];
			dbgPrint(rsum);
			if (left != nullptr) {
				left->lazyft = left->lazyft + lazyft;
				right->lazyft = right->lazyft + lazyft * geomPower[right->al - al];
			}
			lazyft = M_ZERO;
		}
	}
	DZYTree() {}
	DZYTree(int i, int j, vector<ll> &init) : al(i), ar(j), rsum(M_ZERO), lazyft(M_ZERO), left(nullptr), right(nullptr) {
		if (i == j) {
			rsum[1] = rsum[2] = init[i];	
		} else {
			int k = (i + j) / 2;
			left = new DZYTree(i, k, init);
			right = new DZYTree(k + 1, j, init);
			combine();
		}
	}
	void addToRange(int i, int j) {
		propagate();
		if (j < al || ar < i) return;
		else if (i <= al && ar <= j) {
			lazyft = lazyft + geomPower[al - i + 1];
			propagate();
		} else {
			left->addToRange(i, j); right->addToRange(i, j);
			combine();
		}
	}
	matrix rangeSum(int i, int j) {

		if (j < al || ar < i) return M_ZERO;
                propagate();
		if (i <= al && ar <= j) return rsum;
		else return left->rangeSum(i, j) + right->rangeSum(i, j);
	}
};

int main() {
	M_FIB[1] = M_FIB[2] = M_FIB[3] = 1;
	M_ID[0] = M_ID[3] = 1;
	geomPower[0] = M_ID;
	for (int i = 1; i < NMAX; ++i) geomPower[i] = geomPower[i-1] * M_FIB;
	dbgPrint(M_ID); dbgPrint(M_FIB);
	dbgPrint(geomPower[1]);
	geomSum[0] = geomPower[0];
	for (int i = 1; i < NMAX; ++i) geomSum[i] = geomSum[i-1] + geomPower[i];
	int n, m; scanf("%d %d", &n, &m);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	DZYTree cfing(0, n-1, arr);
	for (int qta = 0; qta < m; ++qta) {
		for (int i = 0; i < n; ++i) {
//			dbgPrint(cfing.rangeSum(i, i));
		}
		int t, l, r; scanf("%d %d %d", &t, &l, &r); --l; --r;
		if (t == 1) {
			cfing.addToRange(l, r);
		} else {
			matrix ans = cfing.rangeSum(l, r);
			printf("%lld\n", ans[1]);
		}
	}
	return 0;
}