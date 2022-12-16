// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=5e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn];
bool dp[maxn];
ll n,k,d;
bool val[4*maxn];

ll lower(ll num){
	ll l=1,r=n,an=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(a[mid]>=num){
			an=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return an;
}

void ADD(ll f,ll l=0,ll r=n,ll ind=1){
	if(l>r)return;
	if(f<l||r<f)return;
	val[ind]=1;
	if(l==r)return;
	ll mid=(l+r)/2;
	ADD(f,l,mid,2*ind);
	ADD(f,mid+1,r,2*ind+1);
}

ll ASK(ll f,ll s,ll l=0,ll r=n,ll ind=1){
	if(l>r)return 0;
	if(s<l||r<f)return 0;
	if(f<=l&&r<=s)
		return val[ind];
	ll mid=(l+r)/2;
	return (ASK(f,s,l,mid,2*ind)|ASK(f,s,mid+1,r,2*ind+1));
}


int main(){
	cin>>n>>k>>d;
	FOR(i,1,n)
		cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	ADD(0);
	FOR(i,1,n){
		ll l=lower(a[i]-d);
		ll r=i-k+1;
		if(r<=0)continue;
		if(l>r)continue;
		l--;r--;
		dp[i]=ASK(l,r);
		if(dp[i])
			ADD(i);
	}
	cout<<(dp[n]?"YES":"NO");
}