#include <bits/stdc++.h>

using namespace std;

struct NikitaTree {
	int al, ar;
	int ssz, emptyPops;
	NikitaTree *left, *right;
	NikitaTree() {}
	void combine() {
		int newSize = right->ssz, newEPs = left->emptyPops;
		if (right->emptyPops > left->ssz) {
			newEPs += right->emptyPops - left->ssz;
		} else {
			newSize += left->ssz - right->emptyPops;
		}
		ssz = newSize, emptyPops = newEPs;
	}
	int leftActualSize() {
		return max(0, left->ssz - right->emptyPops);
	}
	NikitaTree(int i, int j) : al(i), ar(j), ssz(0), emptyPops(0) {
		if (i != j) {
			int k = (i + j) / 2;
			left = new NikitaTree(i, k);
			right = new NikitaTree(k + 1, j);
		}
	}
	// 1 = push, -1 = pop
	void setOperation(int i, int v) {
		if (i < al || ar < i) return;
		else if (al == ar) {
			if (v == 1) ssz = 1;
			else emptyPops = 1;
		} else {
			left->setOperation(i, v);
			right->setOperation(i, v);
			combine();
		}
	}
	// yeet
	int getPointAdded(int k) {
		if (al == ar) return al;
		if (k < leftActualSize()) return left->getPointAdded(k);
		else return right->getPointAdded(k - leftActualSize());
	}
};

int main() {
	int m; scanf("%d", &m);
	vector<int> pushedAt(m, -1);
	NikitaTree veerus(0, m-1);
	for (int i = 0; i < m; ++i) {
		int p, t; scanf("%d %d", &p, &t);
		--p;
		if (t == 0) { // pop
			veerus.setOperation(p, -1);
		} else {
			scanf("%d", &pushedAt[p]);
			veerus.setOperation(p, 1);
		}
		if (veerus.ssz == 0) printf("-1\n");
		else printf("%d\n", pushedAt[veerus.getPointAdded(veerus.ssz - 1)]);
	}
	return 0;
}