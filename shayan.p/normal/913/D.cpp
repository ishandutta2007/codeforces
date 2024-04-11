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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=2e5+10;
const ll maxt=1e4+10;

struct BIT{
	ll tree[maxt+10];
	ll ask(ll ind){
		ll sum=0;
		while(ind>0){
			sum+=tree[ind];
			ind-=(ind & -ind);
		}
		return sum;
	}
	void add(ll ind,ll num){
		while(ind<maxt){
			tree[ind]+=num;
			ind+=(ind & -ind);
		}
	}
};
BIT number,value;
vector<pll>v;
pair<pll,ll> p[maxn];

int main(){
	ll n,T;cin>>n>>T;
	REP(i,n){
		cin>>p[i].F.F>>p[i].F.S;
		p[i].S=i+1;
	}
	sort(p,p+n,greater<pair<pll,ll> >());
	ll now=0;
	FORD(i,n,0){// tedadi ke mikhaim bardarim
		while(now<n&&p[now].F.F>=i){
			number.add(p[now].F.S,1);
			value.add(p[now].F.S,p[now].F.S);
			v.PB(MP(p[now].F.S,p[now].S));
			now++;
		}
		ll l=1,r=maxt,ind=-1;
		while(l<=r){
			ll mid=(l+r)/2;
			if(number.ask(mid)>=i){
				ind=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(ind==-1)continue;//means that there isnt i questions till now
		// ind found
		ll num=(ind==0?0:value.ask(ind-1));
		ll remain=(ind==0?0:i-number.ask(ind-1));
		num+=remain*ind;
		if(num<=T){
			cout<<i<<endl<<i<<endl;
			sort(v.begin(),v.end());
			REP(q,i)
				cout<<v[q].S<<" ";
			return 0;
		}
	}
}