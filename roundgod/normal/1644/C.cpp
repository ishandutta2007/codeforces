#include<bits/stdc++.h>
#define MAXN 5005
#define INF 100000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,a[MAXN];
ll ans[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++) ans[i]=-INF;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			ll s=0;
			for(int j=i;j<=n;j++) 
			{
				s+=a[j];
				ans[j-i+1]=max(ans[j-i+1],s);
			}
		}
		for(int i=0;i<=n;i++)
		{
			ll res=-INF;
			for(int j=0;j<=n;j++) res=max(res,ans[j]+1LL*min(i,j)*x);
			printf("%lld ",res);
		}
		puts("");
	}
	return 0;
}