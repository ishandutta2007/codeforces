#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef long double LD;
const int N=100010;
LL f[N],g[N],ans;
int n;
vector<pair<int,int>>lk[N];
void dfs(int p,int fa)
{
	f[p]=0;g[p]=0;
	for(auto [x,y]:lk[p])
	{
		if(x==fa)continue;
		dfs(x,p);
		g[p]=max(g[p],max(g[x],f[p]+f[x]+y));
		f[p]=max(f[p],f[x]+y);
	}
}
void work(int p,int fa,LL faf,LL fag)
{
	LL mxf1=faf,mxf2=0,mxf3=0,mxf4=0,mxg1=fag,mxg2=0;
	for(auto [x,y]:lk[p])
	{
		if(x==fa)continue;
		if(f[x]+y>mxf1)mxf4=mxf3,mxf3=mxf2,mxf2=mxf1,mxf1=f[x]+y;
		else if(f[x]+y>mxf2)mxf4=mxf3,mxf3=mxf2,mxf2=f[x]+y;
		else if(f[x]+y>mxf3)mxf4=mxf3,mxf3=f[x]+y;
		else if(f[x]+y>mxf4)mxf4=f[x]+y;
		if(g[x]>mxg1)mxg2=mxg1,mxg1=g[x];
		else if(g[x]>mxg2)mxg2=g[x];
	}
	ans=max(ans,mxf1+mxf2+mxf3+mxf4);
	for(auto [x,y]:lk[p])
	{
		if(x==fa)continue;
		LL nf=mxf1==f[x]+y?mxf2:mxf1,ng=mxg1==g[x]?mxg2:mxg1;
		if(mxf1==f[x]+y)ng=max(ng,mxf2+mxf3);
		else if(mxf2==f[x]+y)ng=max(ng,mxf1+mxf3);
		else ng=max(ng,mxf1+mxf2);
		ans=max(ans,2*y+ng+g[x]);
		work(x,p,nf+y,ng);
	}
}
int main()
{
	scanf("%d",&n);
	LL sum=0;
	rep(i,n-1){int x,y,z;scanf("%d%d%d",&x,&y,&z);lk[x].pb(mp(y,z));lk[y].pb(mp(x,z));sum+=2*z;}
	dfs(1,0);
	work(1,0,0,0);
	printf("%lld\n",sum-ans);
    return 0;
}