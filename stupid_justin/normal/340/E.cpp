#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=1e9+7;//
const int N=2005;
int fac[N];
int facinv[N];
int h[N];
int a[N];
int num,cnt;
int n,ans;
int ksm(int x,int y)//
{
	int ret=1;
	while(y)
	{
		if(y&1) ret=(ret*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ret%mod;
}
int Div(int x,int y){return x*ksm(y,mod-2)%mod;}
int calc(int x)
{
    int ret;
    if (x%2==1) ret=-1;else ret=1;
    ret*=Div(fac[cnt],fac[cnt-x]*fac[x]%mod)%mod;ret%=mod;
    ret*=fac[num-x];ret%=mod;
    return  ret;
}
signed main()
{
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		if(a[i]==-1) num++;
 		else h[a[i]]=1;
 	}
    fac[0]=1;
 	for(int i=1;i<=n;i++) if(a[i]==-1&&!(h[i])) cnt++;
 	for(int i=1;i<=num;i++) fac[i]=(fac[i-1]*i)%mod;
    for (int i=1;i<=num;i++) facinv[i]=ksm(fac[i],mod-2);
 	facinv[0]=1;
    ans=fac[num];
 	for(int i=1;i<=cnt;i++) ans+=calc(i),ans%=mod;
    ans=(ans%mod)+mod;
    ans%=mod;
	cout<<ans<<endl;
}