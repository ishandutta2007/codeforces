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
const int N=1e5+100;
int n,q,a[N],b[N],c[N],sum[N],nxt[N],L[N],R[N];
int st[N],h,f[N][21],w,id[N],lg[N];
vector <int> p;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int query(int l,int r)
{
	if (l>r) return 0;
	int p=lg[r-l+1];
	return min(f[l][p],f[r-(1<<p)+1][p]);
}
signed main()
{
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++)
	{
		c[i]=a[i]-b[i];
		sum[i]=sum[i-1]+c[i];
	}
	for (int i=0;i<=n;i++)
	{
		while (h&&sum[st[h]]<sum[i]) nxt[st[h--]]=i;
		st[++h]=i;
	}
	while (h) nxt[st[h--]]=n+1;
	for (int i=1;i<=n;i++) f[i][0]=sum[i];
	lg[0]=-1;
	for (int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=20;j++)
	{
		for (int i=1;i<=n;i++)
		{
			if (i+(1<<j)-1>n) break;
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	while (q--)
	{
		int l=read(),r=read();
		if (r>=nxt[l-1]||sum[r]-sum[l-1]!=0)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",abs(query(l,r)-sum[l-1]));
	}
}