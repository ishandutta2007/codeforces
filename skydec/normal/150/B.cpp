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
#define MAXN 2005
#define jsb 1000000007
int fa[MAXN];int n,m,k;
int get(int x){return (x==fa[x])?x:fa[x]=get(fa[x]);}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i+k-1<=n;i++)
	for(int j=1;j<=k;j++)
	fa[get(i+j-1)]=get(i+k-j);
	int ans=1;
	for(int i=1;i<=n;i++)
	if(fa[i]==i)ans=ans*1ll*m%jsb;
	printf("%d\n",ans);
	return 0;
}