#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
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
const int N=1550,V=1e5+50,pn=1e5+10;
int n,m,K,a,b,p;
int zp[V],fp[V],f[N],sf[N];
int sl[N][N],sr[N][N],dpl[N][N],dpr[N][N],sum[N];
int C(int a,int b)
{
	if(a<b) return 0;
	return mul(zp[a],mul(fp[b],fp[a-b]));
}
int main()
{	
	int i,t,l,r,tmp,all;
	cin>>n>>m;
	cin>>a>>b;p=mul(a,inv(b));
	cin>>K;
	zp[0]=fp[0]=1;
	for(i=1;i<=pn;i++) zp[i]=mul(zp[i-1],i);
	fp[pn]=inv(zp[pn]);
	for(i=pn-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
	for(i=0;i<=min(m-1,K);i++) 
	{
		f[i]=mul(C(K,i),mul(power(p,i),power(sub(1,p),K-i)));
	}
	for(i=0;i<m;i++)
	{
		sf[i]=f[i];
		if(i>0) upd(sf[i],sf[i-1]);
	}
	sl[0][1]=sr[0][m]=1;
	for(t=1;t<=n;t++)
	{
		all=sl[t-1][1];
		for(i=0;i<m;i++)
		{
			sum[i]=mul(sr[t-1][i],f[i]);
			if(i>0) upd(sum[i],sum[i-1]);
		}
		for(r=1;r<=m;r++)
		{
			tmp=0;
			upd(tmp,mul(sub(all,sl[t-1][r+1]),mul(sf[r-1],f[m-r])));
			rdc(tmp,mul(sum[r-1],f[m-r]));
			dpr[t][r]=tmp;
			//printf("#%d %d  %d\n",t,r,tmp);
		}
		for(i=m+1;i>1;i--)
		{
			sum[i]=mul(sl[t-1][i],f[m+1-i]);
			if(i<m+1) upd(sum[i],sum[i+1]);
		}
		for(l=1;l<=m;l++)
		{
			tmp=0;
			upd(tmp,mul(sub(all,sr[t-1][l-1]),mul(sf[m-l],f[l-1])));
			rdc(tmp,mul(sum[l+1],f[l-1]));
			dpl[t][l]=tmp;
		}
		sr[t][0]=0;
		for(i=1;i<=m;i++) sr[t][i]=add(sr[t][i-1],dpr[t][i]);
		sl[t][m+1]=0;
		for(i=m;i>=1;i--) sl[t][i]=add(sl[t][i+1],dpl[t][i]);
	}
	//printf("U%d %d\n",sl[n][1],sr[n][m]);
	printf("%d",sl[n][1]);
	return 0;
}