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

#pragma GCC Optimize("Ofast")

ll a[maxn],sm[maxn];
ll num,str;

ll lower(ll l,ll r,ll ls,ll numb){
	ll ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if((sm[mid]-ls)>numb){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}

int main(){
	ll n,q;cin>>n>>q;
	FOR(i,1,n){
		cin>>a[i];
		sm[i]=sm[i-1]+a[i];
	}
	num=1;
	str=0;
	REP(i,q){
		ll x;cin>>x;
		ll id=lower(num,n,str+sm[num-1],x);
		if(id==-1){
			num=1;
			str=0;
		}
		else{
			str=a[id]-(sm[id]-sm[num-1]-str-x);
			num=id;
		}
		cout<<n+1-num<<endl;
	}
}