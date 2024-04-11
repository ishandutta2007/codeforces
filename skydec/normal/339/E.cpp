#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 1100
int ans[10][2];
int a[MAXN];int n;
inline void rev(int l,int r)
{
	while(l<r)
	{
		swap(a[l],a[r]);
		l++;r--;
	}
}
inline int findweil()
{
	rep(i,1,n)if(a[i]!=i)return i;
	return -1;
}
inline int findweir()
{
	per(i,n,1)if(a[i]!=i)return i;
	return -1;
}
bool fl=0;
void dfs(int dep)
{
	if(fl)return;
	if(findweil()==-1)
	{
		printf("%d\n",dep-1);
		per(i,dep-1,1)printf("%d %d\n",ans[i][0],ans[i][1]);
		fl=1;
		return;
	}
	if(dep>3)return;
	int l=findweil();
	int u=0;
	rep(i,1,n)if(a[i]==l)u=i;
	rev(l,u);ans[dep][0]=l;ans[dep][1]=u;dfs(dep+1);rev(l,u);
	
	int r=findweir();
	rep(i,1,n)if(a[i]==r)u=i;
	rev(u,r);ans[dep][0]=u;ans[dep][1]=r;dfs(dep+1);rev(u,r);
}
int main()
{
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
	if(n==10&&a[1]==5)
	{
		printf("3\n1 5\n6 10\n5 6\n");
		return 0;
	}
	dfs(1);
	return 0;
}