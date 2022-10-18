 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int T,n;
char s[N],t[N];
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
		scanf("%s%s",s+1,t+1);
		int a=0,b=0,x=0,y=0,ans=inf;
		for (int i=1;i<=n;i++)
		{
			if (s[i]!=t[i])
			{
				a++;
				if (s[i]=='1') x++;
				else y++;
			}
			else b++;
		}
		if (a%2==0&&x==y) ans=min(ans,a);
		x=y=0;
		for (int i=1;i<=n;i++) if (s[i]==t[i])
		{
			if (s[i]=='1') x++;
			else y++;
		}
		if (b%2==1&&x==y+1) ans=min(ans,b);
		if (ans==inf) printf("-1\n");
		else printf("%d\n",ans);

	}
}