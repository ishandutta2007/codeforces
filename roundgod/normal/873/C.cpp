#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN][MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int ans1=0,ans2=0;
	for(int i=1;i<=m;i++)
	{
		int cnt=0,res=0,save=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1)
			{
				int s=0,q=0;
				for(int p=j;p<=min(j+k-1,n);p++)
					if(a[p][i]==1) s++;
				if(s>res)
				{
					res=s;
					save=cnt;
				}
				cnt++;
			}
		}
		ans1+=res;
		ans2+=save;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}