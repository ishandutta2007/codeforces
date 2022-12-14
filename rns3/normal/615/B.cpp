#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	ll i,j,k,l,n,m,v[100005];
	cin>>n>>m;
	vector<ll> a[100005];
	for(i=0;i<m;i++) {
		cin>>j>>k;
		a[j].push_back(k);
		a[k].push_back(j);
	}
	ll ma=0;
	for(i=1;i<=n;i++) {
		v[i] = 1;
		for(j=0;j<a[i].size();j++) {
			if(a[i][j] < i) 
				v[i] = max(v[i],v[a[i][j]]+1);
		}
		ma = max(ma,v[i]*(ll)a[i].size());
	}
	cout<<ma;
	return 0;
}