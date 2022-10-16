#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,inv2=499122177,inv6=166374059,lim=1000000;
long long f[1111111],g[1111111],sf[1111111],sg[1111111];
long long cal2(long long x)
{
	x%=MOD;
	return x*(x+1)%MOD*inv2%MOD;
}
long long cal3(long long x)
{
	x%=MOD;
	return x*(x+1)%MOD*(x+2)%MOD*inv6%MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	g[0]=1;
	sg[0]=1;
	for(int i=1;i<=lim;i++)
	{
		g[i]=g[i-1]+cal2(g[i-1])+g[i-1]*sg[i-2];
		sg[i]=sg[i-1]+g[i];
		g[i]%=MOD;
		sg[i]%=MOD;
	}
	f[0]=sf[0]=1;
	for(int i=1;i<=lim;i++)
	{
		f[i]=cal2(g[i-1])+g[i-1]*sg[i-2];
		sf[i]=sf[i-1]+f[i];
		f[i]%=MOD;
		sf[i]%=MOD;
	}
	int n;
	cin>>n;
	long long ans=0;
	for(int L=0;L<=n-1;L++)
	{
		ans+=f[L]*sf[n-L-1]%MOD;
	}
//	cerr<<ans<<endl;
	ans+=(cal3(g[n-1])+g[n-1]*cal2(sg[n-2])%MOD+cal2(g[n-1])*sg[n-2]%MOD)*2;
	ans+=f[n]*2%MOD;
	cout<<ans%MOD<<endl;
//	for(int i=1;i<=n;i++)cerr<<i<<' '<<f[i]<<' '<<g[i]<<endl;
	return 0;
}