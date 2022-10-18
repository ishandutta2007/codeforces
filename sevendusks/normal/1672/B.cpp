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
int T;
char s[N];
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
		scanf("%s",s+1);
		int n=strlen(s+1),sum=0;bool bl=1;
		for (int i=1;i<=n;i++)
		{
			if (s[i]=='A') sum++;
			else sum--;
			if (sum<0) bl=0;
		}
		if (sum==n) bl=0;
		if (s[n]!='B') bl=0;
		if (bl) puts("YES");
		else puts("NO");
	}
}