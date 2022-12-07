#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
#define inv(x) power(x,Mod-2)
using namespace std;
typedef long long ll;
const int Mod=998244353;
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
const int N=3e5+50;
int n,m=0,ans=0;
int a[N],f[N],g[N];
int main()
{
	int i,val,ny,ny2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);m+=a[i];
	}
	ny=inv(m);ny2=inv(n-1);
	f[0]=n-1;
	for(i=1;i<m;i++)
	{
		val=add(mul(mul(i,ny),f[i-1]),1);
		f[i]=mul(val,inv(mul(m-i,mul(ny,ny2))));
	}
	for(i=m-1;i>=0;i--) g[i]=add(g[i+1],f[i]);
	for(i=1;i<=n;i++) upd(ans,g[a[i]]);
	//for(i=0;i<m;i++) printf("#%d %d\n",i,f[i]);
	rdc(ans,mul(n-1,g[0]));
	ans=mul(ans,inv(n));
	printf("%d\n",ans);
	return 0;
}