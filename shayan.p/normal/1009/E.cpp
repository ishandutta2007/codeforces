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
const ll maxn=1e6+10;
const ll mod=998244353;

ll tw[maxn],ans,sm;

int main(){
    ll n;scanf("%lld",&n);
    tw[n-1]=1;
    FORD(i,n-2,0){
	tw[i]=(tw[i+1]*2)%mod;
    }
    FOR(i,1,n){
	ll x;scanf("%lld",&x);
	ans=(ans+sm+(x*tw[i-1]))%mod;
	sm=(sm+x*tw[i])%mod;
    }
    printf("%lld",ans);
}