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

const ll inf=1e14;
const ll maxn=2e5+10;
const ll mod=1e9+7;
const ll SQ=1e6+10;

ll a[maxn];
vector<pll>vec;

inline ll MODD(ll a,ll b,ll c,ll md){
    return (((a*b)%md)*c)%md;
}

inline void NO(){
    cout<<"NO";
    exit(0);
}
inline void YES(){
    cout<<"YES";
    exit(0);
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    if(a==inf||b==inf)return inf;
    a/=gcd(a,b);
    if(a>(inf/b))return inf;
    return a*b;
}

void tajzie(ll x){
    FOR(i,2,SQ){
	ll nm=1;
	while(x%i==0){
	    x/=i;
	    nm*=i;
	}
	if(nm!=1)
	    vec.PB(MP(nm,0));
    }
    if(x!=1)
	vec.PB(MP(x,0));
}

pll Gcd(ll a,ll b){
	if(b==0) return MP(a,0);
	pll p=Gcd(b,a%b);
	return MP(p.S,p.F-((a/b)*p.S));
}

ll inv(ll a,ll md) {
	return (Gcd(a,md).F+md)%md;
}

ll solve_reminders(){
    ll M=1,ans=0;
    for(auto x:vec)
	M*=x.F;
    for(auto x:vec){
	ll MI=M/x.F;
	ll MIR=inv(MI,x.F);
	ll d=((MI*MIR)%M)*x.S;
	ans=(ans+d)%M;
    }
    return ans;
}

int main(){
    ll n,m,k;cin>>n>>m>>k;// tartib n,m nemidoonam
    ll LCM=1;
    REP(i,k){
	cin>>a[i];
	LCM=lcm(LCM,a[i]);
    }
    if(LCM>n) NO();
    tajzie(LCM);
    REP(i,k){
	REP(j,sz(vec)){
	    if(a[i]%vec[j].F==0)
		vec[j].S=k-1-i;
	}
    }
    ll ans=solve_reminders();
    if(ans>m) NO();
    ans=ans+((m-ans)/LCM)*LCM;
    if((ans-k)<0) NO();
    REP(i,k){
	if(gcd(ans-k+1+i,LCM)!=a[i])
	    NO();
    }
    YES();
}