/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=55;
int T,n,pos[N*N];
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
		scanf("%s%s",s+1,t+1);
		for (int i=1;i<=26;i++) pos[s[i]]=i;
		n=strlen(t+1);int ans=0;
		for (int i=2;i<=n;i++) ans+=abs(pos[t[i]]-pos[t[i-1]]);
		printf("%d\n",ans);
	}
}