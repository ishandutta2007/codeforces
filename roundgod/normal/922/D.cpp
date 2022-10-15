#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
string S[MAXN];
struct node
{
	ll h,s,id;
}a[MAXN];
bool cmp(node x,node y)
{
	return x.s*y.h>x.h*y.s;
}
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
	{
		ll cnt1=0,cnt2=0;
		cin>>S[i];
		for(ll j=0;j<S[i].size();j++)
			if(S[i][j]=='h') cnt1++; else cnt2++;
		a[i].h=cnt1;
		a[i].s=cnt2;
		a[i].id=i;
	}
	sort(a,a+n,cmp);
	ll ans=0;
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		ll id=a[i].id;
		for(ll j=0;j<S[id].size();j++)
			if(S[id][j]=='s') cnt++; else ans+=cnt;
	}
	printf("%I64d\n",ans);
	return 0;
}