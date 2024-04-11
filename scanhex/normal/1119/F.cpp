#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=250250;
const nagai oo=8e18/1000000;
vector<pair<int,int>>g[N];
vector<pair<int,int>>gcost[N];
vector<int>good[N];
int ptr[N];

int n;
int k;
int lastgood[N];
int last[N];
set<pair<int,int>>ftx[N],lst[N];
nagai dp[N][2];
nagai curans[N];
void ins(int u,pair<int,int>e){
	if(!ftx[u].count(e)){
		curans[u]+=e.first;
		ftx[u].insert(e);
	}
}
void era(int u,pair<int,int>e){
	if(ftx[u].count(e)){
		curans[u]-=e.first;
		ftx[u].erase(e);
	}
}
nagai getsumx(int u,int x){
	if(x<=0)
		return 0;
	if(ftx[u].size()+lst[u].size()<x)
		return oo;
	while(ftx[u].size()<x){
		auto lol=*lst[u].begin();
		ins(u,lol);
		lst[u].erase(lol);
	}
	while(ftx[u].size()>x){
		auto lol=*ftx[u].rbegin();
		era(u,lol);
		lst[u].insert(lol);
	}
	return curans[u];
}
void solve(int u,int p=-1){
	last[u]=k;
	nagai beg=0;
	vector<nagai>kek;
	for(int i=0;i<ptr[u];++i){
		int v=g[u][i].first;
		nagai w=g[u][i].second;
		if(v==p)continue;
		solve(v,u);
		beg+=dp[v][0];
		kek.emplace_back(w+dp[v][1]-dp[v][0]);
	}
	sort(kek.begin(),kek.end());
	nagai s=beg;
	int needskip=sz(g[u])-k;
	dp[u][0]=dp[u][1]=oo;
//	if(k==1)
//		cerr<<"beg "<<ptr[u]<<' '<<beg<<'\n';
	for(int i=0;i<=kek.size();++i){
		dp[u][0]=min(dp[u][0],s+getsumx(u,needskip-i));
		dp[u][1]=min(dp[u][1],s+getsumx(u,needskip-i-1));
		if(i<kek.size())
			s+=kek[i];
	}
	dp[u][1]=min(dp[u][0],dp[u][1]);
//	cerr<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n-1;++i){
		 int a,b,c;
		 cin>>a>>b>>c;
		 --a,--b;
		 g[a].emplace_back(b,c);
		 g[b].emplace_back(a,c);
	}
	for(int i=0;i<n;++i){
		sort(g[i].begin(),g[i].end(),[&](pair<int,int>a,pair<int,int>b){
				 return g[a.first].size()>g[b.first].size();
				});
		gcost[i]=g[i];
		sort(gcost[i].begin(),gcost[i].end(),[&](pair<int,int>a,pair<int,int>b){
				return a.second<b.second;
				});
		for(int j=0;j<g[i].size();++j)
			good[j].push_back(i);
		ptr[i]=g[i].size();
	}
	fill(last,last+N,-1);
	fill(lastgood,lastgood+N,-1);
	for(int i=0;i<n;++i)
		for(auto&[x,y]:g[i]){
			lst[i].insert({y,x});
		}
	for(k=0;k<n;++k){
//		if(k==1)return 0;
		for(int x:good[k]){
			while(ptr[x]>0&&g[g[x][ptr[x]-1].first].size()<=k)
				--ptr[x];
			lastgood[x]=k;
			for(int i=0;i<ptr[x];++i){
				auto p=make_pair(g[x][i].second,g[x][i].first);
				lst[x].erase(p);
				era(x,p);
			}
		}
//		for(int x:good[k])
//			for(int i=0;i<ptr[x];++i)
//				mem[x].erase(g[x][i]);
		nagai ans=0;
		for(int x:good[k])
			if(last[x]<k){
				solve(x);
				ans+=dp[x][0];
			}
		for(int x:good[k]){
			for(int i=0;i<ptr[x];++i){
				auto p=make_pair(g[x][i].second,g[x][i].first);
				lst[x].insert(p);
				while(ftx[x].size()&&lst[x].size()&&ftx[x].rbegin()->first>lst[x].begin()->first){
					ins(x,*lst[x].begin());
					lst[x].erase(*lst[x].begin());
//					era(x,*ftx[x].rbegin());
				}
			}
		}
//		for(int x:good)
//			for(int i=0;i<ptr[x];++i)
//				mem[x].insert(g[x][i]);
		cout<<ans<<' ';
	}
	cout<<'\n';
	return 0;
}