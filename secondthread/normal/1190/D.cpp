#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct SegTree {
	SegTree *lChild, *rChild;
	int leftmost, rightmost;
	int sum=0;
	SegTree(int l, int r):leftmost(l), rightmost(r),
	lChild(NULL), rChild(NULL) {}

	void pointUpdate(int index) {
		if (leftmost==rightmost) {
			sum=1;
			return;
		}
		if (index<=(leftmost+rightmost)/2) {
			if (lChild==NULL) 
				lChild=new SegTree(leftmost, (leftmost+rightmost)/2);
			lChild->pointUpdate(index);
		}
		else {
			if (rChild==NULL)
				rChild=new SegTree((leftmost+rightmost)/2+1, rightmost);
			rChild->pointUpdate(index);
		}
		sum=0;
		if (lChild!=NULL)
			sum+=lChild->sum;
		if (rChild!=NULL)
			sum+=rChild->sum;
	}
	ll rangeQuery(int l, int r) {
		if (l<=leftmost&&r>=rightmost) {
			return sum;
		}
		if (l>rightmost||r<leftmost) return 0;
		ll total=0;
		if (lChild!=NULL)
			total+=lChild->rangeQuery(l, r);
		if (rChild!=NULL)
			total+=rChild->rangeQuery(l, r);
		return total;
	}
};

struct Vec {
	int x, y;
	Vec(int x, int y): x(x), y(y) {}
	
	bool operator< (const Vec &other) const {
		if (y!=other.y) return y>other.y;
		return x<other.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<Vec> points;
	for (int i=0; i<n; i++) {
		int x, y; cin>>x>>y; points.push_back(Vec(x, y));
	}
	sort(points.begin(), points.end());
	set<int> xs;
	int pointIndex=0;
	ll total=0;
	const int maxX=1000000001;
	SegTree st(0, maxX);
	while (pointIndex<points.size()) {
		//add all at y
		int y = points[pointIndex].y;
		int prevX=0;
		int oldPointIndex=pointIndex;
		while (pointIndex<points.size()&&points[pointIndex].y==y) {
			st.pointUpdate(points[pointIndex++].x);
		}

		pointIndex=oldPointIndex;
		while (pointIndex<points.size()&&points[pointIndex].y==y) {
			int x=points[pointIndex].x;
			st.pointUpdate(x);
			ll left=st.rangeQuery(prevX+1, x);
			ll right=st.rangeQuery(x, maxX);
			total+=left*right;
			//cout<<"trying x "<<x<<" left: "<<left<<" right: "<<right<<endl;
			prevX=x;
			pointIndex++;
		}
	}
	cout<<total<<endl;

	return 0;
}