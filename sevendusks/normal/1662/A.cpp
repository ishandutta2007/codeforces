/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int T,n,MAX[11];
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
		memset(MAX,-0x3f,sizeof(MAX));
		for (int i=1;i<=n;i++)
		{
			int a=read(),b=read();
			MAX[b]=max(MAX[b],a);
		}
		if (any_of(MAX+1,MAX+11,[](int x){return x<0;}))
		{
			printf("MOREPROBLEMS\n");
			continue;
		}
		printf("%d\n",accumulate(MAX+1,MAX+11,0));
	}
}