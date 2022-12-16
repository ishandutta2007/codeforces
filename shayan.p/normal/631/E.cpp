// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

// #### MIN HULL // Descending input
struct Hull{
    pll line[maxn];
    ll Count=0;
    inline ll get(ll x,ll ind){
	return (line[ind].F*x)+line[ind].S;
    }
    bool is_bad(pll PS,pll NW,pll FU){
	if(FU.F==NW.F) return FU.S<NW.S;// paralal line
	return ((NW.S-PS.S)*(NW.F-FU.F)) >= ((NW.S-FU.S)*(NW.F-PS.F));
    }
    void add(ll a,ll b){
	line[Count++]=MP(a,b);
	while(Count>=3&&is_bad(line[Count-3],line[Count-2],line[Count-1])){
	      line[Count-2]=line[Count-1];
	      Count--;
	}
    }
    ll ask(ll x){// Count==0 !!
	ll l=0,r=Count-1;
	while(l<r){
	    ll mid=(l+r)/2;
	    if(get(x,mid)>get(x,mid+1))
		l=mid+1;
	    else
		r=mid;
	}
	return get(x,l);
    }
};

ll sm[maxn],a[maxn];

int main(){
    ll n,ans=0,delta=0;cin>>n;
    Hull hull;
    FOR(i,1,n){
	cin>>a[i];
	sm[i]=sm[i-1]+a[i];
	ans+=a[i]*i;
    }
    hull.Count=0;
    FORD(i,n,1){
	hull.add(i,sm[i]);
	delta=max(delta,sm[i]-i*a[i]-hull.ask(-a[i]));
    }
    hull.Count=0;
    FOR(i,1,n){
	hull.add(-i,sm[i-1]);
	delta=max(delta,sm[i-1]-i*a[i]-hull.ask(a[i]));
    }
    
    ans+=delta;
    cout<<ans;
}