#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
char a[200005];
int pre[26][200005];
inline int sum(int c,int l,int r)
{
	return l==0?pre[c][r]:pre[c][r]-pre[c][l-1];
}
int dfs(int o,int l,int r)
{
	if(l==r)return o!=a[l];
	int m=l+r>>1;
	int u=m-l+1-sum(o,l,m)+dfs(o+1,m+1,r);
	int v=r-m-sum(o,m+1,r)+dfs(o+1,l,m);
	return u<v?u:v;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",a);
		for(int i=0;i<n;i++)a[i]-=97;
		for(int i=0;i<26;i++)pre[i][0]=0;
		pre[a[0]][0]=1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<26;j++)
			{
				if(a[i]==j)pre[j][i]=pre[j][i-1]+1;
				else pre[j][i]=pre[j][i-1];
			}
		}
		printf("%lld\n",dfs(0,0,n-1));
	}
}