// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=5010;
const ll big=5001;

ll dp[maxn][maxn];
ll a[maxn];

int main(){
	ll n;cin>>n;
	FOR(i,1,n)
		cin>>a[i];
	FOR(i,1,n){
		FOR(j,0,n){
			if(j>a[i])continue;
			if(a[i]>=big)
				dp[i][j]=1+dp[i-1][min(a[i-1],j)];
			else
				dp[i][j]=min(1+dp[i-1][min(a[i-1],j)],a[i]-j+dp[i-1][min(a[i-1],a[i])]);
		}
	}
	cout<<dp[n][0];
}