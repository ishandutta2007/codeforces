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
const ll maxn=510;
const ll mod=1e9+7;

ll a[maxn];

int main(){
    ll n,m;cin>>n>>m;
    ld ans=0;
    FOR(i,1,n){
	cin>>a[i];
    }
    REP(i,m){
	ll x,y,z;cin>>x>>y>>z;
	ans=max(ans,(z==0?ld(0):(ld(a[x]+a[y])/ld(z))));
    }
    cout<<setprecision(15)<<fixed<<ans;
}