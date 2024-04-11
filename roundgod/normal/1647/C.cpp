#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
		if(str[1][1]=='1')
		{
			puts("-1");
			continue;
		}
		printf("%d\n",n*m);
		for(int i=n;i>=1;i--)
			for(int j=m;j>=1;j--)
			{
				if(str[i][j]=='0') printf("%d %d %d %d\n",i,j,i,j);
				else if(i>1) printf("%d %d %d %d\n",i-1,j,i,j);
				else printf("%d %d %d %d\n",i,j-1,i,j);
			}
	}
	return 0;
}