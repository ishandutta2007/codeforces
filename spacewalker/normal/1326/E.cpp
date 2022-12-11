#include <bits/stdc++.h> 
using namespace std;
constexpr int INF = 500000000; 

struct BombTree {
	int al, ar;
	int rsum, minpsum;
	BombTree *left, *right;
	BombTree(int i, int j) : al(i), ar(j), rsum(0), minpsum(0) {
		if (i != j) {
			int k = (i + j) / 2;
			left = new BombTree(i, k);
			right = new BombTree(k + 1, j);
		}
	}
	void add(int i, int v) {
		if (i < al || ar < i) return;
		else if (al == ar) {
			rsum += v, minpsum += v;
		} else {
			left->add(i, v);
			right->add(i, v);
			rsum = left->rsum + right->rsum;
			minpsum = min(left->minpsum, left->rsum + right->minpsum);
		}
//		printf("range %d %d minpsum %d\n", al, ar, minpsum);
	}
	pair<int, int> getRangeInfo(int i, int j) {
		// returns {range sum, min prefix sum}
		if (ar < i ||  j < al) return make_pair(0, INF);
		else if (i <= al && ar <= j) {
			return make_pair(rsum, minpsum);
		} else {
			auto lres = left->getRangeInfo(i, j);
			auto rres = right->getRangeInfo(i, j);
			return make_pair(lres.first + rres.first, min(lres.second, lres.first + rres.second));
		}
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<int> locInP(n);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		locInP[x - 1] = i;
	}
	int ans = n - 1;
	BombTree withBombs(0, n - 1);
	for (int i = 0; i < n; ++i) {
		// check positiveOnly for the prefix,
		// then check withBombs to see if it dips below zero
		int toBomb; scanf("%d", &toBomb); --toBomb;
		printf("%d ", ans + 1);
		withBombs.add(toBomb, -1);
		while (ans >= 0) {
			int prefValue = withBombs.getRangeInfo(locInP[ans], n - 1).second;
			prefValue = min(prefValue, 0);
			if (locInP[ans] > 0) {
				int rEnd, rMinVal;
				tie(rEnd, rMinVal) = withBombs.getRangeInfo(0, locInP[ans] - 1);
				prefValue += rEnd - min(0, rMinVal);	
			}
			if (prefValue < 0) {
				withBombs.add(locInP[ans], 1);
				--ans;
			} else break;
		}
	}
	printf("\n");
	return 0;
}