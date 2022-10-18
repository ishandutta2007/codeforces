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
int T,n,a[N],sum[N];

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
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);
		long double ans=-1e18;
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		for (int i=1;i<n;i++) ans=max(ans,(long double)1.0*sum[i]/i+1.0*(sum[n]-sum[i])/(n-i));
		double tmp=ans;
		printf("%.9lf\n",tmp);
	}
}