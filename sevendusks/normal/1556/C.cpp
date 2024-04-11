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
const int N=1100;
int n,c[N],sum[N];
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
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if (i&1) sum[i]+=c[i];
		else sum[i]-=c[i];
	}
	int ans=0;
	for (int i=1;i<n;i+=2)
	{
		int MAX=1,s=0;
		for (int j=i+1;j<=n;j+=2)
		{
			if (MAX<=c[i])
			{
				int to=MAX+sum[j-1]-sum[i];
				if (to<=c[j]) ans+=min(c[i]-MAX+1,c[j]-to+1);
			}
			MAX=max(MAX,s+c[j]);
			s+=c[j]-c[j+1];
		}
	}
	printf("%lld\n",ans);
}