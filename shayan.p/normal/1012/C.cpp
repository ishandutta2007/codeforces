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
const ll maxn=5010;
const ll mod=1e9+7;

ll dp[2][maxn][maxn],a[maxn];

int main(){
    REP(i,2){
	REP(j,maxn){
	    REP(k,maxn){
		dp[i][j][k]=inf;
	    }
	}
    }
    REP(i,maxn){
	dp[0][i][0]=0;
    }
    dp[1][1][1]=0;
    
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
    }
    FOR(i,2,n){
	FOR(j,1,n){
	    dp[0][i][j]=min(dp[0][i-1][j],dp[1][i-1][j]+(a[i]>=a[i-1]?(a[i]-a[i-1]+1):ll(0)));
	    ll h1=a[i]-1,h2=min(a[i],a[i-2])-1,tmp1=(a[i-1]>h1?(a[i-1]-h1):ll(0)),tmp2=(a[i-1]>h2?(a[i-1]-h2):ll(0));
	    dp[1][i][j]=min(tmp1+dp[0][i-2][j-1],tmp2+dp[1][i-2][j-1]);
	}
    }
    FOR(i,1,(n/2)+(n%2)){
	cout<<min(dp[0][n][i],dp[1][n][i])<<" ";
    }
}