#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=4*1e5+100;
int t,n,a[N],f[N][21],lg[N];
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
	int len=r-l+1,p=lg[len];
	return gcd(f[l][p],f[r-(1<<p)+1][p]);
}
inline bool check(int mid)
{
	int v=ask(1,mid);
	for (int i=2;i<=n;i++) if (ask(i,i+mid-1)!=v) return 0;
	return 1;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read(),a[n+i]=a[i];
		for (int i=1;i<=2*n;i++) f[i][0]=a[i];
		lg[0]=-1;
		for (int i=1;i<=2*n;i++) lg[i]=lg[i>>1]+1;
		for (int j=1;j<=20;j++)
		{
			for (int i=1;i<=2*n;i++)
			{
				if (i+(1<<j)-1>2*n) break;
				f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
		bool bl=1;
		for (int i=1;i<=n;i++) if (a[i]!=a[1]) bl=0;
		if (bl)
		{
			printf("0\n");
			continue;
		}
		int l=1,r=n;
		while (l<r)
		{
			int mid=(l+r)>>1;
			if (check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",r-1);
	}
}