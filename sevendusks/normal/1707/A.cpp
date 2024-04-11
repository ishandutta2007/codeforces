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
int T,n,q,a[N],vi[N];
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
		n=read();q=read();
		for (int i=1;i<=n;i++) a[i]=read(),vi[i]=0;
		int x=0;
		for (int i=n;i>=1;i--)
		{
			if (x+1<=a[i]&&x<q) x++,vi[i]=1;
			else if (x>=a[i]) vi[i]=1;
		}
		for (int i=1;i<=n;i++) printf("%d",vi[i]);
		printf("\n");
	}
}