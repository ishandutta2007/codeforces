#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=300300;
vector<pair<int,nagai>>g[N];
nagai flux[N];

int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		 int u,v,d;
		 cin>>u>>v>>d;
		 --u,--v;
		 g[u].emplace_back(v,d);
		 flux[u]+=d;
		 flux[v]-=d;
	}
	vector<int>pos,neg;
	for(int i=0;i<n;++i)
		if(flux[i]>0)
			pos.push_back(i);
		else if(flux[i]<0)
			neg.push_back(i);
	vector<array<nagai,3>>ans;
	while(pos.size()&&neg.size()){
		int i=pos.back();
		int j=neg.back();
		nagai fl=min(flux[i],-flux[j]);
		ans.push_back({i,j,fl});
		flux[i]-=fl;
		flux[j]+=fl;
		if(flux[i]==0)
			pos.pop_back();
		if(flux[j]==0)
			neg.pop_back();
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans)
		cout<<x[0]+1<<' '<<x[1]+1<<' '<<x[2]<<'\n';
	return 0;
}