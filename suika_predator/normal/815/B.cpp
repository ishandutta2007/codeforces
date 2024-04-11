#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;
const int MOD=1e9+7;
int n,m,a[7][233333];
int fact[233333];
inline int inv(int x)
{
	int bit=1<<30,y=MOD-2;
	long long ret=1;
	while(bit)
	{
		ret*=ret,ret%=MOD;
		if(bit&y)ret*=x,ret%=MOD;
		bit>>=1;
	}
	return ret;
}
inline int C(int n,int m)
{
	return 1ll*fact[n]*inv(fact[m])%MOD*inv(fact[n-m])%MOD;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<=200000;i++)fact[i]=1ll*fact[i-1]*i%MOD;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[1][i]);
	}
	if(n==1)return printf("%d\n",a[1][1]),0;
	int l=2,t=n-1,cur=1;
	for(;;l++,t--)
	{
		for(int j=1;j<=t;j++)
		{
			if(cur)a[l][j]=a[l-1][j]+a[l-1][j+1];
			else a[l][j]=a[l-1][j]-a[l-1][j+1];
			if(a[l][j]>=MOD)a[l][j]-=MOD;
			if(a[l][j]<0)a[l][j]+=MOD;
			cur^=1;
		}
		if(t%4==1)break;
	}
	//for(int i=1;i<=l;i++){for(int j=1;j<=n+1-i;j++)cout<<a[i][j]<<' ';cout<<endl;}
	long long ans=0;
	for(int i=1;i<=t;i+=2)
	{
		//cout<<C(t/2,i/2)<<' '<<a[l][i]<<' '<<1ll*C(t/2,i/2)*a[l][i]<<endl;
		ans+=1ll*C(t/2,i/2)*a[l][i]%MOD;
		ans%=MOD;
	}
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}