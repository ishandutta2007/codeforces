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
const ll maxn=510,maxn2=25e4+10;
const ll mod=1e9+7;

ll dp[maxn][maxn];// cnt // length
ll tw[maxn2];

int main(){
    tw[0]=1;
    FOR(i,1,maxn2-1){
	tw[i]=(2*tw[i-1])%mod;
    }
    ll n,k;cin>>n>>k;
    dp[0][0]=1;
    FOR(i,1,k){
	FOR(j,1,n){
	    FOR(w,0,j-1){
		dp[i][j]=(dp[i][j]+((tw[w*(j-w)]*(tw[j-w]-1))%mod)*dp[i-1][w])%mod;
	    }
	}
    }
    ll ans=0;
    FOR(i,0,n){
	ans=(ans+tw[i*(n-i)]*dp[k][i])%mod;
    }
    cout<<ans;
}