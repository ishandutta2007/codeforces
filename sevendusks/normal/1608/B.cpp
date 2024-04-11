 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int T,n,a,b;
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
		n=read();a=read();b=read();
		if (abs(a-b)>1||a+b>n-2)
		{
			printf("-1\n");
			continue;
		}
		if (a==b)
		{
			for (int i=1,l=1,r=a+b+1;i<=a+b+1;i++)
			{
				if (i&1) printf("%d ",l++);
				else printf("%d ",r--);
			}
			for (int i=a+b+2;i<=n;i++) printf("%d ",i);
			printf("\n");
		}
		if (a>b)
		{
			for (int i=1,l=n-(a+b+2)+1,r=n;i<=a+b+2;i++)
			{
				if (i&1) printf("%d ",l++);
				else printf("%d ",r--);
			}
			for (int i=n-(a+b+2);i>=1;i--) printf("%d ",i);
			printf("\n");
		}
		if (a<b)
		{
			for (int i=1,l=1,r=a+b+2;i<=a+b+2;i++)
			{
				if (i&1) printf("%d ",r--);
				else printf("%d ",l++);
			}
			for (int i=a+b+3;i<=n;i++) printf("%d ",i);
			printf("\n");
		}
	}
}