#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,t1,t2,s1[15],s2[15],a[15],inv[2000001],f[1<<14];
const int mod=1e9+7;
signed main()
{
	n=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	inv[0]=inv[1]=1;
	for(int i=2;i<=2000000;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<(1<<n);i++)
	{
		f[i]=1;
		for(int l=(i-1)&i;l;l=(l-1)&i)
		{
			int x=l^i;
			t1=t2=0;
			for(int j=0;j<n;j++)
			{
				if((l>>j)&1)
					s1[++t1]=j;
				if((x>>j)&1)
					s2[++t2]=j;
			}
			int cnt=1;
			for(int i1=1;i1<=t1;i1++)
				for(int l1=1;l1<=t2;l1++)
					(cnt*=a[s1[i1]]*inv[a[s1[i1]]+a[s2[l1]]]%mod)%=mod;
			(f[i]+=mod-cnt*f[l]%mod)%=mod;	
		}
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		t1=t2=0;
		for(int l=0;l<n;l++)
			if((i>>l)&1)
				s1[++t1]=l;
			else
				s2[++t2]=l;
		int cnt=1;
		for(int i1=1;i1<=t1;i1++)
			for(int l1=1;l1<=t2;l1++)
				(cnt*=a[s1[i1]]*inv[a[s1[i1]]+a[s2[l1]]]%mod)%=mod;
		(ans+=cnt*f[i]%mod*t1%mod)%=mod; 
	}
	cout<<ans;
	return 0;
}