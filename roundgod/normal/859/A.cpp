#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int main()
{
	scanf("%d",&n);
	int res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		res=max(res,a[i]);
	}
	if(res<=25) puts("0"); else printf("%d\n",res-25);
	return 0;
}