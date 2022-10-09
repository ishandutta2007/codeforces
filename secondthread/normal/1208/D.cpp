
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree {
	SegTree *lChild, *rChild;
	ll minVal, leftmost, rightmost, delta;
	SegTree(int leftmost, int rightmost, vector<ll> &a):
		leftmost(leftmost), rightmost(rightmost), delta(0) {
		if (leftmost!=rightmost) {
			int mid=(leftmost+rightmost)/2;
			lChild=new SegTree(leftmost, mid, a);
			rChild=new SegTree(mid+1, rightmost, a);
			minVal=min(lChild->minVal, rChild->minVal);
		}
		else {
			minVal=a[leftmost];
		}
	}
	ll getMin() {
		return minVal+delta;
	}
	int indexOfLast(ll value) {
		if (leftmost==rightmost) return leftmost;
		if (rChild->getMin()+delta==value) return rChild->indexOfLast(value-delta);
		return lChild->indexOfLast(value-delta);
	}
	void update(int l, int r, ll by) {
		if (l<=leftmost&&r>=rightmost) { delta+=by; return;}
		if (r<leftmost||l>rightmost) return;
		lChild->update(l, r, by);
		rChild->update(l, r, by);
		minVal=min(lChild->getMin(), rChild->getMin());
	}

};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<ll> a(n);
	for (int i=0; i<n; i++) cin>>a[i];
	SegTree st(0, n-1, a);
	vector<int> ans(n);
	for (int i=1; i<=n; i++) {
		int index=st.indexOfLast(0);
		ans[index]=i;
		st.update(index+1, n-1, -i);
		st.update(index, index, 1000000000000000000ll);
	}
	for (int i:ans) cout<<i<<' ';
	cout<<'\n';

	return 0;
}