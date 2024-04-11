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
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn];
bool is[maxn];

int main(){
	ll n,k,l;cin>>n>>k>>l;
	ll N=n*k;
	REP(i,N)
		cin>>a[i];
	sort(a,a+N);
	
	ll res=n,x=0;
	
	REP(i,N){
		if(a[i]-a[0]<=l)
			x=i;
	}
	REP(i,n){
		if((i*k)<=x){
			is[i*k]=1;
			res--;
		}
		else
			break;
	}
	FORD(i,x,0){
		if(res==0)
			break;
		if(!is[i]){
			is[i]=1;
			res--;
		}
	}
	if(res!=0){
		cout<<0;
		return 0;
	}
	ll ans=0;
	REP(i,N)
		ans+=(is[i]*a[i]);
	cout<<ans;
}