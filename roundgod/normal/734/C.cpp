#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,x,s;
P a[MAXN];
int c[MAXN],d[MAXN],e[MAXN],res[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&x,&s);
	for(int i=0;i<m;i++)
		scanf("%d",&a[i].S);
	for(int i=0;i<m;i++)
		scanf("%d",&a[i].F);
	sort(a,a+m);
	for(int i=0;i<m;i++)
		e[i]=a[i].F;
	e[m]=INF+1;
	int t=INF;
	for(int i=0;i<m;i++)
	{
		t=min(t,a[i].S);
		res[i]=t;
	}
	for(int i=0;i<k;i++)
		scanf("%d",&c[i]);
	for(int i=0;i<k;i++)
		scanf("%d",&d[i]);
	ll ans=1LL*INF*INF;
	for(int i=0;i<k;i++)
	{
		if(d[i]>s) continue;
		int rest=s-d[i];
		int t=upper_bound(e,e+m+1,rest)-e;
		if(t==0) ans=min(ans,1LL*x*(n-c[i]));
		else ans=min(ans,1LL*min(x,res[t-1])*(n-c[i]));
	}
	t=upper_bound(e,e+m+1,s)-e;
	if(t==0) ans=min(ans,1LL*x*n);
	else ans=min(ans,1LL*min(x,res[t-1])*n);
	printf("%I64d\n",ans);
	return 0;
}