#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int t,n,a[N],b[N];
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
		for (int i=2;i<=n;i++)
		{
			b[i]=0;
			for (int j=0;j<30;j++) if ((a[i-1]>>j)&1&&!((a[i]>>j)&1)) b[i]|=(1<<j);
			a[i]^=b[i];
		}
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}	
}