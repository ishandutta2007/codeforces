#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],b[MAXN];
ll find_ans(ll d)
{
	ll ans=0;
	b[1]=a[1];
	for(ll i=2;i<=n;i++)
	{
		if(a[i]-b[i-1]>d+1||a[i]-b[i-1]<d-1) return INF;
		if(a[i]-b[i-1]!=d) ans++;
		b[i]=b[i-1]+d;
	}
	return ans;
}
int main()
{
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++) scanf("%I64d",&a[i]);
	if(n==1||n==2)
	{
		puts("0");
		return 0;
	}
	ll ans=INF,mini=INF,maxi=-INF;
	for(ll i=2;i<=n;i++) mini=min(mini,a[i]-a[i-1]),maxi=max(maxi,a[i]-a[i-1]);
	if(maxi-mini>4||maxi<mini) {puts("-1"); return 0;}
	for(ll i=mini;i<=maxi;i++)
	{
		ans=min(ans,find_ans(i));
		a[1]--;
		ans=min(ans,find_ans(i)+1);
		a[1]+=2;
		ans=min(ans,find_ans(i)+1);
		a[1]--;
	}
	if(ans==INF) puts("-1"); else printf("%I64d\n",ans);
	return 0;
}