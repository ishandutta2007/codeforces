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
int T,n,m,pos[N];
char s[N],t[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int solve(char c)
{
	m=0;
	for (int i=1;i<=n;i++) if (s[i]!=c) t[++m]=s[i],pos[m]=i;
	pos[0]=0;pos[m+1]=n+1;
	for (int i=1;i<=m/2;i++) if (t[i]!=t[m+1-i]) return inf;
	int l=1,r=m,ans=count(s+1,s+1+n,c);
	for (int i=1;i<=m/2;i++)
	{
		ans-=2*min(pos[l]-pos[l-1]-1,pos[r+1]-pos[r]-1);
		l++;r--;
	}
	int x=(m+1)/2;
	if (m&1) ans-=2*min(pos[x]-pos[x-1]-1,pos[x+1]-pos[x]-1);
	else ans-=(pos[x+1]-pos[x]-1);
	return ans;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		scanf("%s",s+1);
		int ans=inf;
		for (char c='a';c<='z';c++) ans=min(ans,solve(c));
		if (ans==inf) printf("-1\n");
		else printf("%d\n",ans);
	}
}