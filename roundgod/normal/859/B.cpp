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
	int res=INF;
	for(int i=1;i*i<=n;i++)
		res=min(res,2*(i+(n-1)/i+1));
	printf("%d\n",res);
	return 0;
}