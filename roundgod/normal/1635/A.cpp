#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			res|=a[i];
		}
		printf("%d\n",res);
	}
	return 0;
}