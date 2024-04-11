/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int T,n,p[110];
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
		if (n==3)
		{
			printf("3 2 1\n1 3 2\n3 1 2\n");
			continue;
		}
		for (int i=1;i<=n;i++) p[i]=p[n+i]=n-i+1;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<n;j++) printf("%d ",p[i+j]);
			printf("\n");
		}
	}
}