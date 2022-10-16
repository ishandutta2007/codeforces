#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=3e5+5;
const int mod=998244353;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,m,tot,ans;
char ch[N];
int cnt[N],sum[N];
vector<int> a[N];

void init()
{
	int l=max(n,m);
	cnt[0]=cnt[1]=0;cnt[2]=1;
	for (int i=3;i<=l;i++)
	{
		cnt[i]=(ksm(2,i-3)+cnt[i-2])%mod;
	}
	sum[0]=sum[1]=0;sum[2]=1;
	for (int i=3;i<=l;i++)
	{
		sum[i]=sum[i-1]*2%mod;
		sum[i]=(sum[i]+cnt[i])%mod;
	}
}
signed main()
{
	rd(n);rd(m);
	init();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		a[i].push_back(0);
		for (int j=1;j<=m;j++) 
		{
			if (ch[j]=='*') a[i].push_back(1);
			else a[i].push_back(0);
		}
		a[i].push_back(1);
	}
	for (int j=0;j<=m+1;j++) a[n+1].push_back(1);
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if(a[i][j]==0) tot++;
    
	for (int i=1;i<=n;i++)
	{
		int len=0;
		for (int j=1;j<=m+1;j++)
		{
			if (a[i][j]==0) len++;
			else ans=(ans+sum[len]*ksm(2,tot-len)%mod)%mod,len=0;
		}
	}
	for (int j=1;j<=m;j++)
	{
		int len=0;
		for (int i=1;i<=n+1;i++)
		{
			if (a[i][j]==0) len++;
			else ans=(ans+sum[len]*ksm(2,tot-len)%mod)%mod,len=0;
		}
	}
	cout<<ans<<endl;

}