#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define p3 pair<pll,ll>
#define F first
#define S second
using namespace std;
const ll maxn=2e5+10,Big=1e9;
ll n,t,a[maxn],ans[maxn];
ll num[1000010];
p3 q[maxn];
ll block;
bool cmp(p3 a,p3 b)
{
	if(a.F.F/block==b.F.F/block) return a.F.S<b.F.S;
	return a.F.F/block<b.F.F/block;
}
int main()
{
	cin>>n>>t;for(ll i=0;i<n;i++) scanf("%ld",&a[i]);
	for(ll i=0;i<t;i++) {scanf("%ld",&q[i].F.F);scanf("%ld",&q[i].F.S);q[i].S=i;}
	block=sqrt(n);
	sort(q,q+t,cmp);
	ll L=0,R=0,power=a[0];num[a[0]]++;
	for(ll i=0;i<t;i++)
	{
		ll l=q[i].F.F-1,r=q[i].F.S-1;
		while(L<l) {power-=(2*num[a[L]]-1)*a[L];num[a[L]]--;L++;}
		while(L>l) {L--;power+=(2*num[a[L]]+1)*a[L];num[a[L]]++;}
		while(R<r) {R++;power+=(2*num[a[R]]+1)*a[R];num[a[R]]++;}
		while(R>r) {power-=(2*num[a[R]]-1)*a[R];num[a[R]]--;R--;}
		ans[q[i].S]=power;
	}
	for(ll i=0;i<t;i++) {ll A=ans[i]/Big,B=ans[i]%Big,dig=0;if(A!=0){printf("%ld",A);ll cop=B;while(cop>0) {cop/=10;dig++;} for(ll i=0;i<9-dig;i++) printf("%d",0);}printf("%ld\n",B);}
}