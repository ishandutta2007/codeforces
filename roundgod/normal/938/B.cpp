#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int main()
{
	scanf("%d",&n);
	int res=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		res=max(res,min(x-1,1000000-x));
	}
	printf("%d\n",res);
	return 0;
}