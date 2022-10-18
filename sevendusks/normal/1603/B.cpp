/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
int t,x,y,n;
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
		x=read(),y=read();
		if (y>=x)
		{
			int k=y/x,a=(y%x)/2;
			printf("%lld\n",n=x*k+a);
			assert(n%x==y%n);
			continue;
		}
		printf("%lld\n",n=x+y);
		assert(n%x==y%n);
	}
}