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
int T,cnt[26],ok[N];
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
		int n=strlen(s+1);
		memset(cnt,0,sizeof(cnt));
		fill(ok+1,ok+1+n,0);
		for (int i=n;i>=1;i--)
		{
			int now=s[i]-'a';
			if (!cnt[now])ok[i]=1;
			cnt[now]=1;
		}
		for (int i=1;i<=n;i++) if (ok[i])
		{
			for (int j=i;j<=n;j++) printf("%c",s[j]);
			printf("\n");
			break;
		}
	}
}