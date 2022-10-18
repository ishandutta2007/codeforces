/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int t,n,a[N],sum[N];
bool f[N][550];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int get(int i,int j)
{
	int r=i+j-1;
	return sum[r]-sum[i-1];
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
		int lim;
		for (int i=n;i>=1;i--) if (i*(i+1)/2<=n){lim=i;break;}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=lim;j++) f[i][j]=0;
			f[i][1]=1;
		}
		int ans=1;
		for (int j=2;j<=lim;j++)
		{
			int MAX=-inf;
			for (int i=n-j+1;i>=1;i--)
			{
				int r=i+j-1,now=get(i,j);
				f[i][j]=(MAX>now);
				if (f[i][j]) ans=j;
				if (f[r][j-1]) MAX=max(MAX,get(r,j-1));
			}
		}
		printf("%lld\n",ans);
	}	
}