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

inline ll Ciel(ll a,ll b){
    return (a/b)+((a%b)!=0);
}
    
pll best(ll n){
    ll sq=sqrt(n);
    ll m=inf;
    FOR(i,-10,10){
	if((sq+i)<=0)continue;
	m=min(m,sq+i+Ciel(n,sq+i));
    }
    FOR(i,-10,10){
	if((sq+i)<=0)continue;
	if((sq+i+Ciel(n,sq+i))==m)return {sq+i,Ciel(n,sq+i)};
    }
}

int main(){
    ll n;cin>>n;
    pll p=best(n);
    ll nw=1;
    while(nw<=n){
	FORD(i,min(nw+p.F-1,n),nw){
	    cout<<i<<" ";
	}
	nw=min(nw+p.F,n+1);
    }
}