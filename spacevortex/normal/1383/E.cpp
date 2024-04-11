#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
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
const int N=2e6+50;
int n,L,R,ans,val=0;
int a[N],dp[N];
char s[N];
void chg(int x,int w)
{
	val=add(val,sub(w,dp[x]));
	dp[x]=w;
}
int main()
{
	int i,l,r,len;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++) a[i]=s[i]-'0';
	L=1;
	while(L<=n&&a[L]==0) L++;
	if(L==n+1)
	{
		printf("%d\n",n);
		return 0;
	}
	R=n;
	while(a[R]==0) R--;
	dp[R]=1;
	for(r=R-1;r>=L;r=l-1)
	{
		l=r;
		if(a[r]==1)
		{
			if(a[r+1]==1) chg(0,dp[r+1]);
			dp[r]=add(val,1);
		}
		else
		{
			while(a[l-1]==0) l--;
			len=r-l+1;
			for(i=0;i<=len;i++) chg(i,dp[r+1]);
		}
	}
	//printf("P %d\n",dp[L]);
	ans=mul(dp[L],mul(L,n+1-R));
	printf("%d\n",ans);
	return 0;
}