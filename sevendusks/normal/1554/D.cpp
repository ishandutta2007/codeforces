/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int t,n;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void print(int n,char c)
{
	for (int i=1;i<=n;i++) printf("%c",c);
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		if (n==1)
		{
			printf("a\n");
			continue;
		}
		if (n%2==0)
		{
			int x=n/2;
			print(x,'b');print(1,'a');print(x-1,'b');
		}
		else
		{
			int x=n/2;
			print(x,'b');print(1,'a');print(x-1,'b');print(1,'c');
		}
		printf("\n");
	}
}