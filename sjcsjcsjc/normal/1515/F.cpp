#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int n,m,k,sum,a[300010],p[300010],loc[300010],pos[300010];
vector<pair<int,int> > v[300010];
vector<int> g[300010];

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]); 
}

signed main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	for(int i=1;i<=n;i++) p[i]=i,g[i].push_back(i);
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(make_pair(y,i));
		v[y].push_back(make_pair(x,i));
	}
	if(sum<(n-1)*k){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	vector<int> ans;
	set<pair<int,int> > s;
	for(int i=1;i<=n;i++) s.insert(make_pair(-a[i],i));
	while(s.size()>1){
		pair<int,int> t=*s.begin();
		bool flag=false;
		for(int i=loc[t.second];i<g[t.second].size()&&!flag;i++){
			int x=g[t.second][i],rootx=t.second;
			for(int j=pos[x];j<v[x].size()&&!flag;j++){
				pos[x]++;
				int rooty=find_set(v[x][j].first);
				if(rootx!=rooty){
					if(g[rootx].size()<g[rooty].size()) swap(rootx,rooty);
					p[rooty]=rootx;
					s.erase(s.find(make_pair(-a[rootx],rootx))); 
					a[rootx]+=a[rooty]-k;
					s.erase(s.find(make_pair(-a[rooty],rooty)));
					a[rooty]=0;
					s.insert(make_pair(-a[rootx],rootx));
					for(int l=0;l<g[rooty].size();l++) g[rootx].push_back(g[rooty][l]);
					ans.push_back(v[x][j].second);
					flag=true;
				}
			}
			if(!flag) loc[t.second]++;
		}
	}
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
	return 0;
}