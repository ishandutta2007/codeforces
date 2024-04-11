/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int t,n,a[N];
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
		if (count(a+1,a+1+n,0)==n)
		{
			for (int i=1;i<=n;i++) printf("%d ",i);
			printf("\n");
			continue;
		}
		int ans=0;
		for (int i=0;i<30;i++)
		{
			int cnt=0;
			for (int j=1;j<=n;j++) if (a[j]>>i&1) cnt++;
			ans=__gcd(ans,cnt);
		}
		for (int i=1;i<=ans;i++) if (ans%i==0) printf("%d ",i);
		printf("\n");
	}
}