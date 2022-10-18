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
const int N=5100;
int n,a[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int MIN=inf;
	for (int i=1;i<=n;i++)
	{
		int last=0,ans=0;
		for (int j=i+2;j<=n;j++)
		{
			int c=(last+1+a[j]-1)/a[j];
			ans+=c;last=a[j]*c;
		}
		last=a[i];ans++;
		for (int j=i-1;j>=1;j--)
		{
			int c=(last+1+a[j]-1)/a[j];
			ans+=c;last=a[j]*c;
		}
		// printf("%lld\n",ans);
		MIN=min(MIN,ans);
	}
	printf("%lld\n",MIN);
}