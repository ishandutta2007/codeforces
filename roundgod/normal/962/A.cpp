#include<bits/stdc++.h>
#define MAXN 200005
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
	ll ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum*2>=ans) {printf("%d\n",i); return 0;}
	}
	return 0;
}