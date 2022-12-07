#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
#define inv(x) power(x,Mod-2)
#define cmin(a,b) a=min(a,b)
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=1e6+50,inf=1e9+50;
int W,n1,n2,tot,ans;
int pl[2][N],pr[2][N],p[N],h[2][N],mi[2];
int dp[N],f[2][N],s[2][N];
int qry(int x)
{
	return lower_bound(p+1,p+tot+1,x)-p;
}
int main()
{
	int i,tmp;
	W=rd();n1=rd();n2=rd();
	if(n1==0&&n2==0)
	{
		printf("%d\n",power(2,W));
		return 0;
	}
	tot=0;
	for(i=1;i<=n1;i++)
	{
		pl[0][i]=rd()-1;pr[0][i]=rd();
		p[++tot]=pl[0][i];p[++tot]=pr[0][i];
	}
	for(i=1;i<=n2;i++)
	{
		pl[1][i]=rd()-1;pr[1][i]=rd();
		p[++tot]=pl[1][i];p[++tot]=pr[1][i];
	}
	sort(p+1,p+tot+1);
	tot=unique(p+1,p+tot+1)-p-1;
	for(i=1;i<=tot;i++) h[0][i]=h[1][i]=inf;
	for(i=1;i<=n1;i++)
	{
		pl[0][i]=qry(pl[0][i]);pr[0][i]=qry(pr[0][i]);
		cmin(h[0][pl[0][i]],pr[0][i]);
	}
	for(i=1;i<=n2;i++)
	{
		pl[1][i]=qry(pl[1][i]);pr[1][i]=qry(pr[1][i]);
		cmin(h[1][pl[1][i]],pr[1][i]);
	}
	dp[tot]=1;
	mi[0]=mi[1]=inf;
	for(i=tot-1;i>=1;i--)
	{
		cmin(mi[0],h[0][i]);cmin(mi[1],h[1][i]);
		tmp=mul(sub(power(2,p[i+1]-p[i]),2),dp[i+1]);
		if(mi[1]==inf) f[0][i]=dp[i+1];
		else f[0][i]=sub(s[1][i+1],s[1][mi[1]]);
		
		if(mi[0]==inf) f[1][i]=dp[i+1];
		else f[1][i]=sub(s[0][i+1],s[0][mi[0]]);

		dp[i]=add(add(f[0][i],f[1][i]),tmp);

		f[0][i]=add(f[0][i],tmp);
		f[1][i]=add(f[1][i],tmp);
		s[0][i]=add(f[0][i],s[0][i+1]);
		s[1][i]=add(f[1][i],s[1][i+1]);
		//printf("#%d pos: %d   val: %d %d %d\n",i,p[i],dp[i],f[0][i],f[1][i]);
	}
	ans=mul(dp[1],power(2,W-(p[tot]-p[1])));
	printf("%d\n",ans);
	return 0;
}