/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int T,n,m,r[110],w[110];
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
		n=read();m=read();
		for (int i=1;i<=m;i++) r[i]=read(),w[i]=read();
		int MAX=*max_element(r+1,r+1+m);bool bl=1;
		for (int i=1;i<=m;i++) if (MAX+w[i]>n) bl=0;
		if (bl)
		{
			for (int i=1;i<=MAX;i++) printf("R");
			for (int i=1;i<=n-MAX;i++) printf("W");
			printf("\n");
		}
		else printf("IMPOSSIBLE\n");
	}
}