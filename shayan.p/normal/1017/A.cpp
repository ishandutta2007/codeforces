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
const ll maxn=1010;
const ll mod=1e9+7;

pll p[maxn];

bool CMP(pll a,pll b){
    if(a.F>b.F)return 1;
    if(a.F<b.F)return 0;
    return a.S<b.S;
}

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	ll x=0;
	REP(j,4){
	    ll y;cin>>y;
	    x+=y;
	}
	p[i]={x,i};
    }
    sort(p+1,p+n+1,CMP);
    FOR(i,1,n){
	if(p[i].S==1){
	    cout<<i;
	    return 0;
	}
    }
}