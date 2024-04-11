/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int T,n,a[N],f[N][3];
char s[N],t[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int solve(int l,int r)
{
	static int b[N],w,kind[N];
	int ans=0;w=0;
	for (int i=l;i<=r;)
	{
		int j=i;
		while (j<=r&&a[i]==a[j]) j++;
		b[++w]=j-i;kind[w]=a[i];
		if (kind[w]==0&&b[w]>2) ans+=b[w]-2;
		b[w]=min(b[w],2);
		i=j;
	}
	for (int i=1;i<=w;i++) f[i][0]=f[i][1]=f[i][2]=-inf;
	f[1][b[1]]=0;
	for (int i=1;i<w;i++)
	{
		for (int j=0;j<=2;j++) if (f[i][j]!=-inf)
		{
			int now=min(j,b[i+1]);now=min(now,1);
			int sum=now*2;
			if (kind[i]==0) sum+=j-now;
			f[i+1][b[i+1]-now]=max(f[i+1][b[i+1]-now],f[i][j]+sum);
		}
	}
	return ans+max(f[w][0],max(f[w][1]+(kind[w]==0),f[w][2]+2*(kind[w]==0)));
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		scanf("%s%s",s+1,t+1);
		for (int i=1;i<=n;i++)
		{
			if (s[i]=='0'&&t[i]=='0') a[i]=0;
			else if (s[i]=='1'&&t[i]=='1') a[i]=1;
			else a[i]=2;
		}
		int ans=0;
		for (int i=1;i<=n;)
		{
			int j=i;
			while (j<=n&&(a[i]!=2)==(a[j]!=2)) j++;
			if (a[i]==2) ans+=2*(j-i);
			else ans+=solve(i,j-1);
			i=j;
		}
		printf("%d\n",ans);
	}
}