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
#define MAXN 1100
int n,k;
int d[MAXN],s[MAXN];
int now=0;int ty=0;int ti=0;
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&d[i]);rep(i,1,n)scanf("%d",&s[i]);
	ty=s[1];int now=0;
	rep(i,1,n)
	{
		if(s[i]>ty)ty=s[i];
		now+=s[i];
		while(now<d[i])
		{
			ti+=k;
			now+=ty;
		}
		now-=d[i];
		ti+=d[i];
	}
	printf("%d\n",ti);
	return 0;
}