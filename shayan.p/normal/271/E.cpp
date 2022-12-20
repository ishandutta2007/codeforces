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
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

vector<ll>vec;

int main(){
    ll n,m,d=0;cin>>n>>m;
    REP(i,n){
	ll x;cin>>x;
	d=gcd(d,x-1);
    }
    while(d%2==0)
	d/=2;
    for(ll i=1;(i*i)<=d;i++){
	if(d%i==0){
	    vec.PB(i);
	}
    }
    ll SZ=sz(vec);
    if(vec.back()*vec.back() == d)
	SZ--;
    REPD(i,SZ){
	vec.PB(d/vec[i]);
    }
    ll ans=0;
    for(ll x:vec){
	ll y=x;
	while(y<m){
	    ans+=m-y;
	    y*=2;
	}
    }
    cout<<ans;
}