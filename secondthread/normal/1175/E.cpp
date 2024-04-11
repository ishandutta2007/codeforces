#include <bits/stdc++.h>

using namespace std;
const int maxn=500001;

struct SegTree {
	int leftmost, rightmost;
	SegTree *lChild, *rChild;
	int maxVal=-1;

	SegTree(int leftmost, int rightmost): leftmost(leftmost), rightmost(rightmost) {
		if (leftmost!=rightmost) {
			int mid=(leftmost+rightmost)/2;
			lChild=new SegTree(leftmost, mid);
			rChild=new SegTree(mid+1, rightmost);
		}
	}

	void maxWith(int l, int r, int val) {
		if (l>rightmost||r<leftmost) return;
		if (l<=leftmost&&r>=rightmost) {
			maxVal=max(maxVal, val);
			return;
		}
		lChild->maxWith(l, r, val);
		rChild->maxWith(l, r, val);
	}

	int query(int index) {
		if (leftmost==rightmost)
			return maxVal;
		if (index<=lChild->rightmost) {
			return max(maxVal, lChild->query(index));
		}
		else {
			return max(maxVal, rChild->query(index));
		}
	}
};

int maxAfter[25][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	SegTree segTree(0, maxn);
	int nRanges, nQueries; cin>>nRanges>>nQueries;
	for (int i=0; i<nRanges; i++) {
		int from, to; cin>>from>>to;
		segTree.maxWith(from, to, to);
	}
	for (int i=0; i<maxn; i++)
		maxAfter[0][i]=segTree.query(i);

	for (int times=1; times<25; times++) {
		for (int i=0; i<maxn; i++) {
			maxAfter[times][i]=maxAfter[times-1][maxAfter[times-1][i]];
		}
	}

	for (int qq=0; qq<nQueries; qq++) {
		int from, to; cin>>from>>to;
		if (maxAfter[22][from]<to) {
			cout<<"-1\n";
			continue;
		}
		int bitsToShift=22;
		int rangesTaken=0;
		while (bitsToShift>=0) {
			if (maxAfter[bitsToShift][from]>=to) {
				bitsToShift--;
			}
			else {
				rangesTaken+=1<<bitsToShift;
				from=maxAfter[bitsToShift][from];
			}
		}
		rangesTaken++;
		cout<<rangesTaken<<'\n';
	}
	return 0;
}