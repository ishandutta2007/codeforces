/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
using namespace std;
const int N=2100;
int t,n,a[N],sum[N];
unordered_map <int,int> mp;
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
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
		// for (int i=1;i<=n;i++) printf("%d ",sum[i]);
		// printf("\n");
		bool ok=0;
		for (int i=1;i<n;i++) 
			if (sum[i]==(sum[n]^sum[i])) ok=1;
		// printf("%d\n",ok);
		for (int i=1;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				int a=sum[i],b=sum[j]^sum[i],c=sum[n]^sum[j];
				if (a==b&&b==c) ok=1;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
}