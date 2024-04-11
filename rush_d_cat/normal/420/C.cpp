#include <bits/stdc++.h>
using namespace std;
const int N=300000+10;
int n,p;
map< pair<int,int>,int > mp,vis;
vector<int> g[N];
int a[N];
int main() {
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		int x,y; scanf("%d%d",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
		mp[make_pair(x,y)]++;
		mp[make_pair(y,x)]++;
	}
	for(int i=1;i<=n;i++){
		a[i]=g[i].size();
	}
	sort(a+1,a+1+n);
	a[0]=-1e9;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(r-l>1){
			int m=(l+r)>>1;
			if(a[m]<p-a[i])l=m;else r=m;
		}
		ans+=i-1-l;
	}
	for(int u=1;u<=n;u++){
		for(auto v:g[u]){
			if(vis[make_pair(u,v)])continue;
			vis[make_pair(u,v)]=1;
			if(u<v&&g[u].size()+g[v].size()>=p && ((int)g[u].size()+(int)g[v].size()-mp[make_pair(u,v)])<p)ans--;
		}
	}
	cout<<ans<<endl;
}