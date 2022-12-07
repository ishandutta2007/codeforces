#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=(ll)3e18;
const ll N=50,V=5e6+50;
ll n,K,t1=0,t2=0;
ll p[N],h1[V],h2[V];
void dfs(ll xh,ll w)
{
	if(xh>n) 
	{
		if(xh&1ll) h1[++t1]=w;
		else h2[++t2]=w;
		return ;
	}
	dfs(xh+2,w);
	while(p[xh]<inf/w) 
	{
		w*=p[xh];
		dfs(xh+2,w);
	}
}
ll qry(ll W)
{
	ll top,i,ras=0;
	top=t1;
	for(i=1;i<=t2;i++)
	{
		while(top>0&&h1[top]>W/h2[i]) top--;
		if(top==0) break;
		//printf("U%I64d %I64d\n",top,i);
		ras+=top;
	}
	return ras;
}
int main()
{
	ll i,sl,sr,mid;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++) scanf("%I64d",&p[i]);
	dfs(1,1);dfs(2,1);
	sort(h1+1,h1+t1+1);
	sort(h2+1,h2+t2+1);
	scanf("%I64d",&K);
	sl=1;sr=inf;
	while(sl<sr)
	{
		mid=(sl+sr)>>1;
		if(qry(mid)>=K) sr=mid;
		else sl=mid+1;
	}
	printf("%I64d",sl);
	return 0;
}