#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(x,y) x=add(x,y)
using namespace std;
typedef long long ll;
const int Mod=998244353;
inline int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
inline int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
inline int mul(const int a,const int b){return (ll)a*b%Mod;}
inline int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const int N=4e5+50,pn=4e5+5;
int n,cnt=0;
int he[N],zp[N],fp[N],dp[N];
struct Edge
{
	int v,nxt;
}e[N];
inline void eadd(int uu,int vv)
{
	cnt++;e[cnt].v=vv;e[cnt].nxt=he[uu];he[uu]=cnt;
}
inline int C(int a,int b)
{
	return mul(zp[a],mul(fp[b],fp[a-b]));
}
inline void dfs(int x,int nf)
{
	int i,vv,tot=0,tmp=0;
	dp[x]=1;
	for(i=he[x];i;i=e[i].nxt)
	{
		vv=e[i].v;
		if(vv==nf) continue;
		dfs(vv,x);
		tot++;
		dp[x]=mul(dp[x],dp[vv]);
	}
	if(x==1) tmp=zp[tot];
	else 
	{
		for(i=0;i<=tot;i++) upd(tmp,mul(C(tot,i),mul(zp[i],zp[tot-i])));
	}
	dp[x]=mul(dp[x],tmp);
}
int main()
{
//	freopen("d.in","r",stdin);
	int i,uu,vv,ans;
	scanf("%d",&n);
	zp[0]=fp[0]=1;
	for(i=1;i<=pn;i++) zp[i]=mul(zp[i-1],i);
	fp[pn]=inv(zp[pn]);
	for(i=pn-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&uu,&vv);
		eadd(uu,vv);eadd(vv,uu);
	}
	dfs(1,0);
	//cout<<"P"<<dp[3]<<endl;
	ans=mul(dp[1],n);
	printf("%d",ans);
	return 0;
}