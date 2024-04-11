#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k;
int ans[MAXN][MAXN];
int st[MAXN][32];
int pre[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&ans[1][i]);
	for(int i=2;i<=n;i++)
		for(int j=1;j+i-1<=n;j++)
			ans[i][j]=ans[i-1][j]^ans[i-1][j+1];
	for(int i=2;i<=n;i++)
		for(int j=1;j+i-1<=n;j++)
			ans[i][j]=max(ans[i][j],max(ans[i-1][j],ans[i-1][j+1]));
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",ans[r-l+1][l]);
	}
	return 0;
}