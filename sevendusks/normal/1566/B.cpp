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
int t,n;
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
	t=read();
	while (t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		for (int i=1;i<=n;)
		{
			int j=i;
			while (j<=n&&s[i]==s[j]) j++;
			if (s[i]=='0') ans++;
			i=j;
		}
		ans=min(ans,2);
		printf("%d\n",ans);
	}
}