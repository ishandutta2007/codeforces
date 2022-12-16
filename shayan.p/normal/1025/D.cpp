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
const ll maxn=710;
const ll mod=1e9+7;

bool dp[maxn][maxn][2];// baze l r be tori ke gcd vasati ba k 1 nabashe
ll a[maxn];
bool b[maxn][maxn];

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
    }
    FOR(i,1,n){
	FOR(j,i+1,n){
	    b[i][j]=b[j][i]=(gcd(a[i],a[j])!=1);
	}
    }
    FOR(i,1,n+10){
	dp[i][i-1][0]=dp[i][i-1][1]=1;
    }
    FOR(i,1,n){
	b[0][i]=b[i][0]=b[n+1][i]=b[i][n+1]=1;
    }
    FOR(r,1,n){
	FORD(l,r,1){
	    FOR(k,l,r){
		dp[l][r][0]|=(b[l-1][k]&&dp[l][k-1][1]&&dp[k+1][r][0]);
		dp[l][r][1]|=(b[r+1][k]&&dp[l][k-1][1]&&dp[k+1][r][0]);
	    }
	}
    }
    cout<<(dp[1][n][0]?"Yes":"No");
}