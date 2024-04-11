#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,l,a[MAXN];
int main()
{
	scanf("%I64d%I64d%I64d",&n,&k,&l);
	ll m=n*k;
	for(ll i=1;i<=m;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+m+1);
	a[m+1]=INF+2;
	ll cnt=upper_bound(a+1,a+m+2,a[1]+l)-a;
	cnt--;
	if(cnt<n) {puts("0"); return 0;}
	//printf("%I64d\n",cnt);
	ll ans=0;
	ans+=a[1];
	ll remain=cnt-1,now=2;
	for(ll i=1;i<n;i++)
	{
		ll leap=min(k-1,remain-(n-i));
		now+=leap;
		ans+=a[now];
		remain=cnt-now;
		now++;
	}
	printf("%I64d\n",ans);
	return 0;
}