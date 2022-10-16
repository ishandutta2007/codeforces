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
const int mod=998244353;
int ans=1,cnt,n,k,fac[5001],inv[5001],f[5001];
vector<int> v;
char s[5010];
int C(int x,int y)
{
	if(x<y)
		return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	n=read();
	k=read();
	if(k==0)
	{
		puts("1");
		return 0;
	}
	scanf("%s",s+1);
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=n;i++)
		fac[i]=(fac[i-1]*i)%mod;
	for(int i=2;i<=n;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)
		(inv[i]*=inv[i-1])%=mod;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(s[i]=='1')
		{
			f[i]++;
			v.push_back(i);
		}
	}
	if(f[n]<k)
	{
		puts("1");
		return 0;
	}
	int lstl=-1,lstr=-1;
	for(int i=0;i+k<=v.size();i++)
	{
		int L=v[i],R=v[i+k-1];
		for(int l=v[i]-1;l;l--)
		{
			if(s[l]=='1')
				break;
			L=l;
		}
		for(int l=v[i+k-1]+1;l<=n;l++)
		{
			if(s[l]=='1')
				break;
			R=l;
		}
		(ans+=C(R-L+1,k)+mod-1)%=mod;
		if(lstl!=-1)
			(ans+=mod+1-C(lstr-L+1,k-1))%=mod;
		lstl=L;
		lstr=R;
	}
	cout<<ans;
	return 0;
}