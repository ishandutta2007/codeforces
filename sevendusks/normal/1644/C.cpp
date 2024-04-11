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
int T,n,x,a[N],sum[N],MAX[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();x=read();
		for (int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
		for (int i=1;i<=n;i++) MAX[i]=-inf;
		for (int L=1;L<=n;L++)
		{
			for (int i=1;i<=n-L+1;i++) MAX[L]=max(MAX[L],sum[i+L-1]-sum[i-1]);
		}
		int ans=0;
		for (int i=0;i<=n;i++)
		{
			for (int j=1;j<=n;j++) ans=max(ans,MAX[j]+min(i,j)*x);
			printf("%lld ",ans);
		}
		printf("\n");
	}
}