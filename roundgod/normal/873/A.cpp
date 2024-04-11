#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,x,a[MAXN];
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=0;i<n-k;i++)
		ans+=a[i];
	ans+=k*x;
	printf("%d\n",ans);
	return 0;
}