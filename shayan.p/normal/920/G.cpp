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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll BIG=1e10;
const ll MAX=1e6+10;

ll par[MAX];

ll CNT(ll p,ll x){// how many numbers are there which are less than x and gcd(p,y)=1
	vector<ll>v;v.clear();
	while(p>1){
		ll pr=par[p];
		v.PB(pr);
		while(p%pr==0)
			p/=pr;
	}
	ll ans=0;
	REP(i,(1<<sz(v))){
		ll zarb=1;
		bool parity=0;
		REP(j,sz(v)){
			zarb*=(bit(i,j)?v[j]:1);
			parity^=bit(i,j);
		}
		ans+=(parity?-1:1)*(x/zarb);
	}
	return ans;
}

ll solve(ll p,ll k){
	ll l=1,r=BIG,ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if(CNT(p,mid)<=k-1){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	return ans+1;
}

void prep(){
	for(ll i=2;i<MAX;i++)
		if(par[i]==0)
			for(ll j=i;j<MAX;j+=i)
				par[j]=i;
}

int main(){
	prep();
	ll q;cin>>q;
	REP(i,q){
		ll x,p,k;cin>>x>>p>>k;
		cout<<solve(p,k+CNT(p,x))<<endl;
	}
}