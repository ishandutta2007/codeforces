#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int maxn=1001;

struct djs {
	int n, a[maxn];

	djs(int n): n(n) {
		for (int i=0; i<n; i++) a[i]=i;
	}

	int find(int i) {
		if (a[i]==i) return i;
		return a[i]=find(a[i]);
	}

	void merge(int i, int j) {
		i=find(i); j=find(j);
		if (i==j) return;
		a[j]=i;
	}
	
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q; cin>>n>>q;
	vector<int> par;
	for (int i=0; i<n; i++) par.push_back(i);
	vector<ii> decQueries;
	djs dj(n);
	for (int qq=0; qq<q; qq++) {
		int type; cin>>type;
		int l, r; cin>>l>>r; l--; r--;
		if (type) {
			for (int i=l; i<=r; i++)
				dj.merge(l, i);
		}
		else {
			decQueries.push_back({l, r});
		}
	}
	for (ii &query:decQueries) {
		if (dj.find(query.first) == dj.find(query.second)) {
			cout<<"NO\n";
			return 0;
		}
	}
	
	cout<<"YES\n";
	for (int i=0; i<n; i++) {
		cout<<maxn-dj.find(i)<<" \n"[i==n-1];
	}

	return 0;
}