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
const ll Big=1e9+10;
const ld eps=0.00000001;// change it

#pragma GCC Optimize("Ofast")

ll v1,v2,k,n,l;

bool pos(ld tm){
	ll per=n;
	ld len=l;
	if(v1>=v2){
		return (tm>=(len/ld(v1)));
	}
	while(per>0&&len>0){
		ld t1=len/ld(v1);
		if(t1<=tm)
			return 1;
		ld x=(tm*ld(v1)-len)/(ld(v1)-ld(v2));
		// x is the time which bus wants to return
		if(x>tm)
			return 0;
		per-=k;
		if(per<=0)
			return 1;
		ld lll=x*ld(v2-v1);
		ld X=lll/ld(v1+v2);
		X+=x;
		len-=X*ld(v1);
		tm-=X;
	}
	return (tm>=0);
}

int main(){
	cin>>n>>l>>v1>>v2>>k;
	ld L=0,R=Big,ans;
	while((R-L)>eps){
		ld mid=(L+R)/ld(2);
		if(pos(mid)){
			R=mid;
			ans=mid;
		}
		else{
			L=mid;
		}
	}
	cout<<setprecision(7)<<fixed<<ans;
}