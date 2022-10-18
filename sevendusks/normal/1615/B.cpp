 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,l,r,s[N][21];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	int n=200000;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=20;j++)
		{
			s[i][j]=s[i-1][j];
			if (i>>j&1) s[i][j]++;
		}
	}
	T=read();
	while (T--)
	{
		l=read(),r=read();
		int MAX=0;
		for (int i=0;i<=20;i++) MAX=max(MAX,s[r][i]-s[l-1][i]);
		printf("%d\n",r-l+1-MAX);
	}
}