#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
#define tm aoeuaeou

const int N=100100;
const int K=22;
vector<int>ch[N];
int par[N];

int tm[N];
nagai w[N];
int n,m,k;
map<int,nagai> dp[N];
void d(int u){
	if(!ch[u].size()){
		dp[u][tm[u]]=w[u];
		return;
	}
	for(int v:ch[u]){
		d(v);
	}
	sort(ch[u].begin(),ch[u].end(),[&](int a,int b){return dp[a].size()>dp[b].size();});
	dp[u].swap(dp[ch[u][0]]);
	for(int i=1;i<ch[u].size();++i){
		int v=ch[u][i];
		for(auto[x,y]:dp[v])
			dp[u][x]+=y;
	}
	if(w[u]){
		dp[u][tm[u]]+=w[u];
//		nagai cur=w[u];
//		dp[u][tm[u]+1]-=w[u];
		auto rest=w[u];
		auto it=dp[u].upper_bound(tm[u]);
		while(rest&&it!=dp[u].end()){
			nagai mem=min(rest,it->second);
			it->second-=mem;
			rest-=mem;
			++it;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<n;++i){
		int p;
		cin>>p;
		--p;
		ch[p].push_back(i);
		par[i]=p;
	}
	fill(tm,tm+n,N);
	tm[0]=2*N;
	for(int i=0;i<m;++i){
		int v,d,w;
		cin>>v>>d>>w;
		--v;
		tm[v]=d;
		::w[v]=w;
	}
	d(0);
	nagai cur=0;
	nagai ans=0;
	for(auto[x,y]:dp[0]){
		cur+=y;
		ans=max(ans,cur);
	}
	cout<<ans<<'\n';
	return 0;
}