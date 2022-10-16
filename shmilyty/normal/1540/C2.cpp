#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
const int mod=1e9+7;
int n,q,ans,tot=1,c[101],b[101],L[101],s[10001],f[10001];
map<int,int> mp;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		(tot*=(c[i]+1))%=mod;
	}
	for(int i=1;i<n;i++)
		b[i]=b[i-1]+read();
	q=read();
	while(q--)
	{
		int x=read(),cnt=0,sum=0,p=0;
		bool f1=1,f2=1;
		if(mp.count(x))
		{
			cout<<mp[x]<<endl;
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			p+=c[i];
			L[i]=max(0ll,x*i+cnt);
			if(L[i]!=0)
				f1=0;
			if(L[i]>p)
				f2=0;
			cnt+=b[i];
		} 
		if(f1)
		{
			cout<<tot<<endl;
			continue;
		}
		if(!f2)
		{
			puts("0");
			continue;
		}
		memset(f,0,sizeof(f)); 
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			sum+=c[i];
			s[0]=f[0];
			for(int l=1;l<=sum;l++)
				s[l]=(s[l-1]+f[l])%mod;
			for(int l=sum;l>=0;l--)
				f[l]=(l<=c[i]?s[l]:(s[l]-s[l-c[i]-1]+mod)%mod);
			for(int l=0;l<=min(sum,L[i]-1);l++)
				f[l]=0;
		}
		for(int i=0;i<=sum;i++)
			(ans+=f[i])%=mod;
		mp[x]=ans;
		cout<<ans<<endl; 
	}
	return 0;
}