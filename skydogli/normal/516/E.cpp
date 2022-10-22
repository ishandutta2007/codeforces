#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 200005
int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y);
	int tmp=x;x=y;y=tmp-a/b*x;
	return d;
}
int s[MN],d[MN],id[MN];
int n,m,B,G;
vector<int>g[MN],b[MN];
bool cmp(int a,int b){
	if(s[a]==s[b])return a<b;
	return s[a]<s[b];
}
int solve(int m,int n,int x,vector<int>&g,vector<int>&b){
	if(g.size()==m)return -1;
	int cnt=0;
	for(int i=0;i<g.size();++i){s[++cnt]=g[i]*x%m;d[cnt]=g[i];id[cnt]=cnt;}
	for(int i=0;i<b.size();++i){s[++cnt]=b[i]*x%m;d[cnt]=b[i];id[cnt]=cnt;}
	sort(id+1,id+1+cnt,cmp);
	s[0]=s[id[cnt]]-m;s[id[cnt+1]=cnt+1]=s[id[1]]+m;
	int dis=1e18;
	for(int i=1;i<=cnt;++i)dis=min(dis+n*(s[id[i]]-s[id[i-1]]),d[id[i]]);
	int ans=0;
	for(int i=1;i<=cnt;++i){
		dis=min(dis+n*(s[id[i]]-s[id[i-1]]),d[id[i]]);
		if(s[id[i]]==s[id[i+1]])continue;
		if(s[id[i]]+1==s[id[i]]&&id[i]<=g.size())continue;
		ans=max(ans,dis+(s[id[i+1]]-s[id[i]]-1)*n);
	}
	return ans;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	int x,y,d=exgcd(n,m,x,y);
	scanf("%lld",&B);
	for(int i=0;i<B;++i){
		int x;scanf("%lld",&x);b[x%d].push_back(x/d);
	}
	scanf("%lld",&G);
	for(int i=0;i<G;++i){
		int x;scanf("%lld",&x);g[x%d].push_back(x/d);
	}
	if(d>B+G){puts("-1");return 0;}
	x=(x+m)%m;y=(y+n)%n;
	int ans=0;
	for(int i=0;i<d;++i){
		if(!g[i].size()&&!b[i].size()){puts("-1");return 0;}
		ans=max(ans,solve(m/d,n/d,x,g[i],b[i])*d+i);
		ans=max(ans,solve(n/d,m/d,y,b[i],g[i])*d+i);
	}
	printf("%lld\n",ans);
	return 0;
}