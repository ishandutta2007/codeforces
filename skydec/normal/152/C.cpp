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
char str[105][105];
int n,m;
#define jsb 1000000007
int ans=1;
map<char,char>ls[105];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
	int ans=1;
	for(int j=1;j<=m;j++)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(ls[j][str[i][j]]==0)tot++,ls[j][str[i][j]]='1';
		}
		ans=ans*1ll*tot%jsb;
	}
	printf("%d\n",ans);
	return 0;
}