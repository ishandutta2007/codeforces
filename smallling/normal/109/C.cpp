#include<cstdio>
#include<vector>

using namespace std;

vector<int>g[100010];
int n,x,y,z,cnt,flag[100010];
long long ans;

int check(int x)
{
	while(x)
	{
		if(x%10!=4&&x%10!=7)return 1;
		x/=10;
	}
	return 0;
}

void dfs(int x)
{
	if(flag[x])return;
	flag[x]=1;
	cnt++;
	for(int i=0;i<(int)g[x].size();i++)
		dfs(g[x][i]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(check(z))g[x].push_back(y),g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!flag[i])
		{
			cnt=0;
			dfs(i);
			ans+=1ll*cnt*(n-cnt)*(n-cnt-1);
		}
	printf("%I64d",ans);
}