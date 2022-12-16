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
const ll maxn=2e5+10;
const ll mod=1e9+7;
const ll Big=2e9+10;

#pragma GCC Optimize("Ofast")

inline ll f(ll M,ll m){
	if(M<m)return 0;
	return (((M*(M+1))/2)-((m*(m-1))/2));
}

ll  Binary1(ll n){
	ll l=1,r=Big,an=1;
	while(l<=r){
		ll mid=(l+r)/2;
		ll x=f(mid,1);
		if(x<=n){
			an=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return an;
}

ll Binary2(ll n,ll h){
	ll l=h,r=Big,an=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		ll x=f(mid,h)+f(mid-1,1);
		if(x<=n){
			an=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return an;
}

void ANS(ll num){
	cout<<num;
	exit(0);
}

int main(){
	ll n,h;cin>>n>>h;
	ll num=Binary1(n);
	if(num<=h){
		if(f(num,1)==n)
			ANS(num);
		else
			ANS(num+1);
	}
	num=Binary2(n,h);
	ll x=n-(f(num,h)+f(num-1,1));
	if(x==0)
		ANS((2*num)-h);
	if(x<=num)
		ANS((2*num)-h+1);
	ANS((2*num)-h+2);
}