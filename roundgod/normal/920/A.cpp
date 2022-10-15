#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[MAXN];
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int ans=0;
		for(int i=0;i<k;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			int res=INF;
			for(int j=0;j<k;j++)
				res=min(res,max(i-a[j],a[j]-i)+1);
			ans=max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}