#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=1000100;
nagai a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	nagai n,i;
	cin>>n>>i;
	i*=8;
	i/=n;
	nagai k=i;
	k=min(k,30LL);
	nagai len=1<<k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	int ptr=0;
	int ans=n;
	vector<int>kek(a,a+n);
	kek.erase(unique(kek.begin(),kek.end()),kek.end());
	map<int,int>st;
	for(int i=0;i<n;++i){
		while(ptr<n&&lower_bound(kek.begin(),kek.end(),a[ptr])-lower_bound(kek.begin(),kek.end(),a[i])+1<=len){
			++st[a[ptr]];
			++ptr;
		}
		ans=min(ans,(int)n-(ptr-i));
	}
	cout<<ans<<'\n';
	return 0;
}