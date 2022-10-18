/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
using namespace std;
const int N=110;
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
		for (int i=1;i<n;i++)
		{
			int lim=min(k,a[i]);
			a[i]-=lim;a[n]+=lim;
			k-=lim;
		}
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
	}	
}