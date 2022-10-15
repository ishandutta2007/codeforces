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
int n,d,e;
int main()
{
	scanf("%d%d%d",&n,&d,&e);
	e=e*5;
	int ans=n;
	for(int i=0;i*d<=n;i++)
		ans=min(ans,(n-i*d)%e);
	printf("%d\n",ans);
    return 0;
}