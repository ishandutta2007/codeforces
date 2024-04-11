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
const ll maxn=4e5+10;
const ll mod=1e9+7;

ll par[maxn];

ll Find(ll a){
    return (par[a]<0?a:(par[a]=Find(par[a])));
}
ll Merge(ll a,ll b){
    if((a=Find(a)) == (b=Find(b)))return 0;
    if(par[a]>par[b])swap(a,b);
    par[a]+=par[b];
    par[b]=a;
    return 1;
}

int main(){
    fill(par,par+maxn,-1);
    ll n,m,q;cin>>n>>m>>q;
    ll ans=n+m-1;
    FOR(i,1,q){
	ll a,b;cin>>a>>b;
	ans-=Merge(a,b+n);
    }
    cout<<ans;
}