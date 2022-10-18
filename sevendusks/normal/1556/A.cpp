/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int t,a,b;
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
		a=read();b=read();
		if (a==0&&b==0)
		{
			printf("0\n");
			continue;
		}
		if ((a+b)&1)
		{
			printf("-1\n");
			continue;
		}
		if (a==b) printf("1\n");
		else printf("2\n");
	}
}