/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int t,n,a[N],b[N],f[N][21],lg[N];
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int ask(int l,int r)
{
	int p=lg[r-l+1];
	return gcd(f[l][p],f[r-(1<<p)+1][p]);
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<n;i++) b[i]=abs(a[i+1]-a[i]),f[i][0]=b[i];
		lg[0]=-1;
		for (int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
		for (int j=1;j<=20;j++)
		{
			for (int i=1;i<n;i++)
			{
				if (i+(1<<j)-1>=n) break;
				f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
		int ans=1;
		for (int i=1;i<n;i++)
		{
			int l=i,r=n-1;
			while (l<r)
			{
				int mid=l+((r-l+1)>>1ll);
				if (ask(i,mid)!=1) l=mid;
				else r=mid-1;
			}
			if (l==i)
			{
				if (b[i]!=1) ans=max(ans,2ll);
				continue;
			}
			ans=max(ans,l-i+2);
		}
		printf("%lld\n",ans);
	}
}