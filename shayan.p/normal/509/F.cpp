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
const ll maxn=510;
const ll mod=1e9+7;

ll dp[maxn][maxn],ans[maxn][maxn];
ll a[maxn];

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
    }
    FOR(r,1,n){
	FORD(l,r,1){
	    FOR(k,l+1,r){
		if(a[k]>a[l])
		    dp[l][r]=(dp[l][r]+dp[k][r]*ans[l][k-1])%mod;
	    }
	    ans[l][r]=(l==r?1:dp[l+1][r]);
	    dp[l][r]=(dp[l][r]+ans[l][r])%mod;
	}
    }
    cout<<ans[1][n];
}