#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=200200;
int cu[N];
nagai a[N];

map<pair<int,int>,int>st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	nagai su=accumulate(a,a+n,0LL);
	nagai good=0;
	int q;
	cin>>q;
	while(q--){
		int t,s,u;
		cin>>t>>s>>u;
		--s;
		--u;
		auto p=make_pair(t,s);
		if(st.count(p)){
			 int kek=st[p];
			 if(--cu[kek]<a[kek])
				 --good;
			 st.erase(p);
		}
		if(u>=0){
			if(++cu[u]<=a[u])
				++good;
			st[p]=u;
		}
		cout<<su-good<<'\n';
	}
	return 0;
}