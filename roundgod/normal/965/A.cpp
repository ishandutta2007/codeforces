#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,n,s,p;
int main()
{
	scanf("%d%d%d%d",&k,&n,&s,&p);
	int num=(n-1)/s+1;
	int ans=(k*num-1)/p+1;
	printf("%d\n",ans);
	return 0;
}