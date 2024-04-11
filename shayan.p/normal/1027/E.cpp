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
const ll mod=998244353;

ll dp[maxn][maxn];// block size // max

ll tavan(ll a,ll b){
    ll ans=1;
    while(b>0){
	if(b%2)ans=(ans*a)%mod;
	a=(a*a)%mod;
	b/=2;
    }
    return ans;
}

int main(){
    ll n,k;cin>>n>>k;
    FOR(i,1,n){
	dp[1][i]=2;
    }
    FOR(i,2,n){
	dp[i][1]=2;
	FOR(j,2,i-1){
	    FOR(w,max(1,i-j),i-1){
		dp[i][j]=(dp[i][j]+dp[w][j])%mod;
	    }
	}
	dp[i][i]=tavan(2,i);
	FOR(j,i+1,n){
	    dp[i][j]=dp[i][j-1];
	}
    }
    FORD(j,n,1){
	dp[n][j]=((dp[n][j]-dp[n][j-1])*tavan(2,mod-2))%mod;
    }
    ll ans=0;
    FOR(i,1,n){
	FOR(j,1,n){
	    if((i*j)<k){
		ans=(ans+dp[n][i]*dp[n][j]+mod)%mod;
	    }
	}
    }
    cout<<(ans*2+mod+mod)%mod;
}