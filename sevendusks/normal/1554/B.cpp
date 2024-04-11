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
int t,n,k,a[N];
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
		n=read();k=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int ans=-inf;
		for (int i=1;i<=n;i++)
		{
			int lim=min(n,i+3*k+1);
			for (int j=i+1;j<=lim;j++) ans=max(ans,i*j-k*(a[i]|a[j]));
		}
		printf("%lld\n",ans);
	}
}