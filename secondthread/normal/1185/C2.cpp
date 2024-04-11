#include <bits/stdc++.h>

using namespace std;
const int blockSize=4000;
const int rebuildTime=0;
typedef long long ll;
typedef pair<int, int> ii;

struct SegTree {
	int leftmost, rightmost;
	ll sum;
	int nPeople;
	SegTree *lChild, *rChild;

	SegTree(int leftmost, int rightmost):leftmost(leftmost), rightmost(rightmost), sum(0), nPeople(0) {
		if (leftmost!=rightmost) {
			int mid=(leftmost+rightmost)/2;
			lChild=new SegTree(leftmost, mid);
			rChild=new SegTree(mid+1, rightmost);
		}
	}

	void set(int index, int to) {
		nPeople++;
		sum+=to;
		if (leftmost==rightmost) {
			return;
		}
		else {
			if (index<=lChild->rightmost)
				lChild->set(index, to);
			else
				rChild->set(index, to);
		}
	}

	int queryPeopleLessThan(ll maxSum) {
		//cout<<"Querying people less than "<<maxSum<<" in "<<leftmost<<" "<<rightmost<<endl;
		if (sum<=maxSum) {
			return nPeople;
		}
		if (leftmost==rightmost)
			return 0;
		if (lChild->sum<=maxSum) {
			return rChild->queryPeopleLessThan(maxSum-lChild->sum)+lChild->nPeople;
		}
		return lChild->queryPeopleLessThan(maxSum);
	}

};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, totalTime; 
	cin>>n>>totalTime;
	vector<ii> sortedByTime;
	vector<int> posOf;
	vector<int> a;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp;
		sortedByTime.push_back({temp, i});
		posOf.push_back(0);
		a.push_back(temp);
	}
	sort(sortedByTime.begin(), sortedByTime.end());
	for (int i=0; i<n; i++) {
		posOf[sortedByTime[i].second]=i;
	}
	SegTree st(0, n-1);
	for (int i=0; i<n; i++) {
		int time=totalTime-a[i];
		int keep=st.queryPeopleLessThan(time);
		int remove=i-keep;
		cout<<remove<<' ';
		st.set(posOf[i], a[i]);
	}

	cout<<endl;
	return 0;
}