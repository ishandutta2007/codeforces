#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
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
const int V=1e6+50,pn=1e6+5;
int n,K,ans=0;
int zp[V],fp[V];
int C(int a,int b){return mul(zp[a],mul(fp[b],fp[a-b]));}
int main()
{
	int i,j,tmp,cnt;
	scanf("%d%d",&n,&K);
	zp[0]=fp[0]=1;
	for(i=1;i<=pn;i++) zp[i]=mul(zp[i-1],i);
	fp[pn]=inv(zp[pn]);
	for(i=pn-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			cnt=(n-i)*(n-j);
			tmp=mul(mul(C(n,i),C(n,j)),mul(power(K,cnt),power(K-1,n*n-cnt)));
			if((i+j)&1) ans=sub(ans,tmp);
			else ans=add(ans,tmp);
		}
	}
	printf("%d",ans);
	return 0;
}