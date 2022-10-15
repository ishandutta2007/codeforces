#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int b,g,n;
int main()
{
	scanf("%d%d%d",&b,&g,&n);
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		if(b>=i&&g>=n-i) ans++;
	}
	printf("%d\n",ans);
    return 0;
}