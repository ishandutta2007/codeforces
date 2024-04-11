
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


template <typename T, class Compare = less<T>>
struct RMQ {
	vector<vector<T> > v;
	Compare cmp;

	RMQ(vector<T> a): cmp() {
		int n=a.size(), maxlog=32-__builtin_clz(n), r=1;
		v.resize(maxlog+1, vector<T>(n));
		for (int i=0; i<n; ++i) v[0][i]=a[i];
		for (int e=1; e<=maxlog; ++e, r<<=1)
			for (int i=0; i<n; ++i)
				v[e][i]=min(v[e-1][i], v[e-1][min(n-1, i+r)], cmp);
	}

	ll query(int from, int to) {
		assert(to>=from);
		int oFrom=from, oTo=to;
		to=min(to, (int)v[0].size()-1);
		from=min(from, (int)v[0].size()-1);
		to=max(0, to);
		from=max(0, from);
		int ans;
		if (from==to) ans=v[0][from];
		else {
			int size=to-from+1, e=32-__builtin_clz(size)-1;
			ans=min(v[e][from], v[e][to-(1<<e)+1], cmp);
		}
		bool freeSpace=from!=oFrom||to!=oTo;
		if (freeSpace) {
		//	cerr<<"\t\tHas free space for "<<oFrom<<" "<<oTo<<endl;
			ans=max(ans, 0);
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int nArrays, width; cin>>nArrays>>width;
	vector<vector<ll>> arrays(nArrays, vector<ll>());
	for (int i=0; i<nArrays; i++) {
		int l; cin>>l;
		arrays[i].resize(l);
		for (int j=0; j<l; j++) cin>>arrays[i][j];
	}
	vector<RMQ<ll, greater<ll>>> rmqs;
	for (int i=0; i<nArrays; i++) rmqs.emplace_back(arrays[i]);
	vector<vector<int>> arraysToUpdate(width, vector<int>());
	for (int array=0; array<nArrays; array++) {
		for (int i=0; i<(int)arrays[array].size(); i++) {
			arraysToUpdate[i].push_back(array);
			if (width-1-i>=(int)arrays[array].size())
				arraysToUpdate[width-1-i].push_back(array);
		}
	}
	ll sum=0;
	for (int i=0; i<nArrays; i++) {
		if ((int)arrays[i].size()==width)
			sum+=arrays[i][0];
		else
			sum+=max(0ll, arrays[i][0]);
	}
	cout<<sum<<" ";
	for (int pos=1; pos<width; pos++) {
		//cerr<<"considering pos: "<<pos<<'\n';
		for (int array:arraysToUpdate[pos]) {
			//if I slide as far left as possible
			int rightBound=pos;
			//if I slide as far right as possible
			int leftBound=arrays[array].size()-width+pos;
			//cerr<<"Bounds: "<<leftBound<<" "<<rightBound<<endl;
			int oldRightBound=pos-1;
			int oldLeftBound=arrays[array].size()-width+pos-1;

			ll toSub=rmqs[array].query(oldLeftBound, oldRightBound);
			ll toAdd=rmqs[array].query(leftBound, rightBound);
			sum-=toSub;
			sum+=toAdd;
		}
		cout<<sum<<" ";
	}
	cout<<'\n';

	return 0;
}