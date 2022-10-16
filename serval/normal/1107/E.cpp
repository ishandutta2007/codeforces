#include <cstdio>
using namespace std;
#define cmax(a,b) a=b>a?b:a
long long f[105][105][2][105];
long long g[105][105][2];
bool vis[105][105][2][105];
bool all[105][105][2];
int n;
long long ans;
int w[105];
char s[105];
long long clear(int l,int r,int cur);
long long clear(int l,int r,int cur,int len)
{
	if (vis[l][r][cur][len])
		return f[l][r][cur][len];
	vis[l][r][cur][len]=1;
	int lp=l;
	while (lp<=r&&s[lp]==cur)
		lp++;
	if (lp>r)
		return f[l][r][cur][len]=(r-l+1==len?0:-1e12);
	f[l][r][cur][len]=-1e12;
	for (int i=lp;i<=r;i++)
		if (s[i]==cur&&s[i-1]!=cur)
			cmax(f[l][r][cur][len],clear(lp,i-1,cur^1)+clear(i,r,cur,len-lp+l));
	return f[l][r][cur][len];
}
long long clear(int l,int r,int cur)
{
	if (all[l][r][cur])
		return g[l][r][cur];
	all[l][r][cur]=1;
	g[l][r][cur]=-1e12;
	for (int i=1;i<=r-l+1;i++)
		cmax(g[l][r][cur],clear(l,r,cur,i)+w[i]);
	return g[l][r][cur];
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		s[i]-='0';
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (w[i]+w[j-i]>w[j])
				w[j]=w[i]+w[j-i];
	cmax(ans,clear(1,n,0));
	cmax(ans,clear(1,n,1));
	printf("%lld\n",ans);
	return 0;
}