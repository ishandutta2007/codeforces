#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&s);
		printf("%d\n",s/(1LL*n*n));
	}
	return 0;
}