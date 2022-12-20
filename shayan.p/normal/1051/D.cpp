// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2010,mod=998244353;
const ll inf=1e18;

ll dp[maxn][maxn][2];// ta i om rafte bashim j ta moalefe darim va akharesh injoorie

int main(){
    int n,k;cin>>n>>k;
    
    dp[1][1][0]=dp[1][2][1]=1;
    
    FOR(i,2,n){
	FOR(j,1,k){
	    dp[i][j][0]=(dp[i-1][j-1][0]+dp[i-1][j][0]+2*dp[i-1][j][1])%mod;
	    dp[i][j][1]=(dp[i-1][j-1][0]*2+(j<2?0:dp[i-1][j-2][1])+dp[i-1][j][1])%mod;
	}
    }
    cout<<((dp[n][k][0]+dp[n][k][1])*2)%mod;
}