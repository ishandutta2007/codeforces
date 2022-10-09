#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template <typename T, class Compare = less<T>>
struct RMQ {
	vector<vector<T> > v;
	Compare cmp;

	RMQ(vector<T> &a): cmp() {
		int n=a.size(), maxlog=32-__builtin_clz(n), r=1;
		v.resize(maxlog+1, vector<T>(n));
		for (int i=0; i<n; ++i) v[0][i]=a[i];
		for (int e=1; e<=maxlog; ++e, r<<=1)
			for (int i=0; i<n; ++i)
				v[e][i]=min(v[e-1][i], v[e-1][min(n-1, i+r)], cmp);
	}

	T query(int from, int to) {
		assert(to>=from);
		if (from==to) return v[0][from];
		int size=to-from+1, e=32-__builtin_clz(size)-1;
		return min(v[e][from], v[e][to-(1<<e)+1], cmp);
	}
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int nSpecial; cin>>nSpecial;
	vector<int> validMods(nSpecial);
	for (int i=0; i<nSpecial; i++) cin>>validMods[i];
	sort(validMods.begin(), validMods.end());
	validMods.erase(unique(validMods.begin(), validMods.end()),
			validMods.end());
	int from, to; cin>>from>>to;

	//j can reach i if farthestReachedFrom[i]>j
	vector<int> farthestReachedFrom(from-to+1);
	for (int i=0; i<farthestReachedFrom.size(); i++)
		farthestReachedFrom[i]=i+2;
	for (int mod:validMods) {
		int start=(mod-to%mod)%mod;
		for (int i=start; i<farthestReachedFrom.size(); i+=mod) {
			farthestReachedFrom[i]=i+mod;
		}
	}
	int curAt=from-to;
	int prevMax=farthestReachedFrom[0];
	for (int &i:farthestReachedFrom)
		prevMax=i=max(i, prevMax);
	int cur=0, moves=0;
	while (cur<farthestReachedFrom.size()-1) {
		cur=farthestReachedFrom[cur]-1;
		//cout<<cur<<endl;
		moves++;
	}
	cout<<moves<<endl;
	return 0;
}