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
int a[3];int b[3];
int main()
{
	int n;scanf("%d",&n);
	rep(i,1,n)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u]+=v;b[u]+=w;
	}
	rep(i,1,2)if(a[i]>=b[i])printf("LIVE\n");else printf("DEAD\n");
	return 0;
}