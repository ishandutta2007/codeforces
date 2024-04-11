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
int T,n,a[N],b[N],ta[N],tb[N];
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
		for (int i=1;i<=n;i++) ta[i]=tb[i]=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read(),b[i]=read();
			ta[a[i]]++,tb[b[i]]++;
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans+=(ta[a[i]]-1)*(tb[b[i]]-1);
		ans=n*(n-1)*(n-2)/6-ans;
		printf("%lld\n",ans);
	}
}