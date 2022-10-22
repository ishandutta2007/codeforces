
#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=200200;
int a[N];
int tme[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int q;
	cin>>q;
	vector<pair<int,int>>all;
	for(int i=0;i<q;++i){
		 int t;
		 cin>>t;
		 if(t==1){
			  int p,x;
			  cin>>p>>x;
			  --p;
			  a[p]=x;
			  tme[p]=i;
		 }
		 else{
			 int x;
			 cin>>x;
			 while(all.size()&&all.back().second<x)all.pop_back();
			 all.emplace_back(i,x); 
		 }
	}
	for(int i=0;i<n;++i){
		int ans=a[i];
		int rofl=lower_bound(all.begin(),all.end(),make_pair(tme[i],0))-all.begin();
		if(rofl<all.size())ans=max(ans,all[rofl].second);
		cout<<ans<<' ';
	}
	cout<<'\n';
	return 0;
}