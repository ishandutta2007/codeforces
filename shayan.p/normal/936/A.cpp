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
const ll mod=1e9+7;
const ll maxn=2e5+10;

const ll Big=2e18+10;
const ld eps=0.0000000001;

ll k,d,t,dur;
ld tur;

ld check(ld tm){
	ll num=ll(tm);
	
	if(ld(num/dur)>=(ld(Big)/tur))
		return ld(Big);
			
	ld ans=ld(num/dur)*ld(tur);// overflow?
	
	tm-=ld(ld(num/dur)*ld(dur));
	
	if(tm<=k)
		return ans+tm;
	return ans+ld(k)+ld(ld(tm-ld(k))/2);
}

int main(){
	cin>>k>>d>>t;
	dur=((k/d)+((k%d)!=0))*d;
	tur=k+(ld(dur-k)/2);
	ld l=0,r=Big;
	REP(i,200){
		if(r-l<=eps)
			break;
		ld mid=ld(l+r)/2;
		if(check(mid)<=ld(t))
			l=mid;
		else
			r=mid;
	}
	cout<<setprecision(9)<<fixed<<l;
}