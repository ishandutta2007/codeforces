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
const ll maxn=1e5+10;
const ll mod=1e9+7;

ll sm[maxn],n,d,b;

inline ll ask(ll l,ll r){
    r=min(r,n);
    l=max(l,ll(1));
    if(r<l)return 0;
    return sm[r]-sm[l-1];
}

pll f(ll num){
    ll ans1=0,ans2=0,nw1=0,nw2=0,turn;
    turn=0;
    FOR(i,1,(n/2)+(n%2)){
	turn++;
	ll x=min(num,ask(1,i+d*turn))-nw1;
	if(x<b)ans1++;
	else nw1+=b;
    }
    turn=0;
    FORD(i,n,(n/2)+(n%2)+1){
	turn++;
	ll x=min(n*b-num,ask(i-d*turn,n))-nw2;
	if(x<b)ans2++;
	else nw2+=b;
    }
    return {ans1,ans2};
}


int main(){
    cin>>n>>d>>b;
    FOR(i,1,n){
	cin>>sm[i];
    }
    FOR(i,1,n){
	sm[i]+=sm[i-1];
    }
    ll l=0,r=n*b,ans=inf;
    while(l<=r){
	ll mid=(l+r)/2;
	pll p=f(mid);
	ans=min(ans,max(p.F,p.S));
	if(p.F>p.S)
	    l=mid+1;
	else
	    r=mid-1;
    }
    cout<<ans;
}