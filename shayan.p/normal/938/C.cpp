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
const ll Big=1e9+10;

vector<ll>p;

void tajzie(ll x){
	p.clear();
	ll sq=sqrt(x);
	FOR(i,1,sq)
		if(x%i==0)
			p.PB(i);
}

ll solve2(ll n,ll nm){
	ll l=1,r=Big;
	while(l<=r){
		ll mid=(l+r)/2;
		ll num=n/mid;
		if(num==nm)
			return mid;
		if(num<nm)
			r=mid-1;
		else
			l=mid+1;
	}
	if((n/l)==nm)
		return l;
	return -1;
}

pll solve(ll x){
	REP(i,sz(p)){
		ll a=p[i],b=x/p[i];
		if((a+b)%2==0){
			ll q=(b+a)/2;// n
			ll w=(b-a)/2;// n/m
			if(q<0||w<=0)// momkene bug bokhore bayraye 0 shodane m ya n
				continue;
			ll m=solve2(q,w);
			if(m!=-1)
				return MP(q,m);
		}
	}
	return MP(-1,-1);
}

int main(){
	ll t;cin>>t;
	while(t--){
		ll x;cin>>x;
		if(x==0){
			cout<<1<<" "<<1<<endl;
			continue;
		}
		tajzie(x);
		pll ans=solve(x);
		if(ans.F!=-1)
			cout<<ans.F<<" "<<ans.S<<endl;
		else
			cout<<-1<<endl;
	}
}