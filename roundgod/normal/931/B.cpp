#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	int ans=0;
	for(;n>1;n>>=1,++ans)
	{
		if(a==b)
		{
			printf("%d",ans);
			return 0;
		}
		a=(a+1)/2;b=(b+1)/2;
	}
	puts("Final!");
	return 0;
}