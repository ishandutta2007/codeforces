#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
bool f[305][305][305];
bool go[305][305][305];
int n=100;
int s[305][305];bool g[305][305];
int dfs2(int a,int b)
{
	if(a==0&&b==0)return 0;
	if(g[a][b])return s[a][b];
	g[a][b]=1;
	for(int i=1;i<=a;i++)s[a][b]|=(!dfs2(a-i,b));
	for(int i=1;i<=b;i++)s[a][b]|=(!dfs2(a,b-i));
	for(int i=1;i<=min(a,b);i++)s[a][b]|=(!dfs2(a-i,b-i));
	return s[a][b];
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1){int a;scanf("%d",&a);if(a)printf("BitLGM\n");else printf("BitAryo\n");}
	else if(n==2)
	{
		int a,b;scanf("%d%d",&a,&b);
		if(dfs2(a,b))printf("BitLGM\n");else printf("BitAryo\n");
	}
	else
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		if(a^b^c)printf("BitLGM\n");else printf("BitAryo\n");
	}
}