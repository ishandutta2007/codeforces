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
const int bse=26,mod=998244353;
int n,len[1000001],hsh[1000001],qhsh[1000001],ans[1000001];
char s[1000001];
bool check(int l,int r,int ll,int rr)
{
	int x=((hsh[r]-hsh[l-1]*qhsh[r-l+1])%mod+mod)%mod;
	int y=((hsh[rr]-hsh[ll-1]*qhsh[rr-ll+1])%mod+mod)%mod;
	if(x!=y)
		return 0;
	return 1;
	for(int i=0;i<=r-l;i++)
		if(s[l+i]!=s[ll+i])
			return 0;
}
signed main()
{
	n=read();
	fill(len+1,len+1+n,-1);
	fill(ans+1,ans+1+n,-1);
	scanf("%s",s+1);
	qhsh[0]=1;
	for(int i=1;i<=n;i++)
		qhsh[i]=qhsh[i-1]*bse%mod;
	for(int i=1;i<=n;i++)
		hsh[i]=(hsh[i-1]*bse%mod+s[i]-'a')%mod;
	for(int i=1;i*2<=n;i++)
	{
		int l=0,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(i-mid,i+mid,n+1-i-mid,n+1-i+mid))
				l=mid+1;
			else
				r=mid-1;
		}
		len[i]=len[n+1-i]=l-1;
	}
	int p=(n+1)/2;
	for(int i=(n+1)/2;i;i--)
	{
		p=min(p,i);
		if(~len[i])
			while(i-p<=len[i])
			{
				ans[p]=(i-p)*2+1;
				p--;
			}
	}
	for(int i=1;i<=(n+1)/2;i++)
		cout<<ans[i]<<" ";
	return 0;
}