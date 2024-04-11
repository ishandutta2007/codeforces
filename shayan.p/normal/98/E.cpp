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
const ll maxn=1010;
const ll mod=1e9+7;

ld dp[maxn][maxn];

void DP(ll n,ll m){
    ld x=ld(n),y=ld(m);
    if(dp[n][m]!=-1)return;
    if(m==0){
	dp[n][m]=1;
	return;
    }
    if(n==0){
	dp[n][m]=(1/(y+1));
	return;
    }
    DP(m-1,n);
    DP(m,n-1);
    ld A1=(y/(y+1))*ld(1-dp[m-1][n]),B1=(1/(y+1))+(y/(y+1))*ld(1-dp[m-1][n]);
    ld A2=1,B2=1-dp[m][n-1];
    ld p=(B1-B2)/(A2-B2-A1+B1);
    dp[n][m]=p*(A1-B1)+B1;
}

int main(){
    REP(i,maxn){
	REP(j,maxn){
	    dp[i][j]=-1;
	}
    }
    ll n,m;cin>>n>>m;
    DP(n,m);
    cout<<setprecision(10)<<fixed<<dp[n][m]<<" "<<(1-dp[n][m]);
}