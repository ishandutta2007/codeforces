#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
	scanf("%d",&n);
	if(n<6) puts("-1");
	else
	{
		printf("1 2\n");
		printf("2 3\n");
		printf("2 4\n");
		printf("4 5\n");
		printf("4 6\n");
		for(int i=7;i<=n;i++)
			printf("2 %d\n",i);
	}
	for(int i=2;i<=n;i++)
		printf("%d %d\n",1,i);
	return 0;
}