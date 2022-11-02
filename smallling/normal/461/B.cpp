#include<cstdio>
#include<vector>

#define mo 1000000007

using namespace std;

int o,n,now0,now1;
vector<int>a[100010];
int color[100010],f[100010][2];

void dfs(int x,int fa)
{
	if(color[x]==1)f[x][1]=1;
	else f[x][0]=1;
	for(int i=0;i<(int)a[x].size();i++)
		if(a[x][i]!=fa)
		{
			dfs(a[x][i],x);
			now0=1ll*f[x][0]*((f[a[x][i]][0]+f[a[x][i]][1])%mo)%mo;
			now1=1ll*f[x][1]*((f[a[x][i]][0]+f[a[x][i]][1])%mo)%mo+1ll*f[x][0]*f[a[x][i]][1]%mo;
			f[x][0]=now0;f[x][1]=now1%mo;
		}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d",&o),a[o+1].push_back(i+1),a[i+1].push_back(o+1);
	for(int i=1;i<=n;i++)scanf("%d",&color[i]);
	dfs(1,0);
	printf("%d",f[1][1]);
}