/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1100;
int T,n,a[N];
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
		int ans=0;
		for (int i=1;i<n;i++) ans=max(ans,a[i]+a[i+1]);
		for (int i=1;i<n;i++) ans=max(ans,a[1]+a[i+1]);
		for (int i=n;i>1;i--) ans=max(ans,a[n]+a[n-1]);
		for (int i=2;i<n;i++) for (int j=i;j<n;j++)
		{
			ans=max(ans,a[j]+a[i-1]);
			ans=max(ans,a[i]+a[j+1]);
		}
		printf("%d\n",ans);
	}
}