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
int t,n,a[N],b[N],tr[N];
pair <int,int> c[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read(),c[i]=m_k(a[i],i);
		random_device rd;
		mt19937 g(rd());
		if (n%2==1)
		{
			while (1)
			{
				shuffle(c+1,c+1+n,g);
				int x=n/2;
				if (c[x].first+c[x+2].first!=0) break;
			}
		}
		for (int i=1;i<=n;i++) a[i]=c[i].first,tr[c[i].second]=i;
		if (n%2==0)
		{
			for (int i=1;i<=n/2;i++) b[i]=-a[n+1-i],b[n+1-i]=a[i];
		}
		else
		{
			for (int i=1;i<n/2;i++) b[i]=-a[n+1-i],b[n+1-i]=a[i];
			int x=n/2;
			b[x]=b[x+2]=-a[x+1];
			b[x+1]=a[x]+a[x+2];
		}
		int ans=0,sum=0;
		for (int i=1;i<=n;i++) ans+=a[i]*b[i],sum+=abs(b[i]);
		assert(ans==0&&sum<=1e9);
		for (int i=1;i<=n;i++) printf("%d ",b[tr[i]]);
		printf("\n"); 
	}
}