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

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll mod=1e9+7;
const ll maxn=110;
const ll maxchar=30;

#pragma GCC Optimize("Ofast")

vector<pair<ll,char> >v[maxn];
ll dp[maxn][maxn][maxchar];//-1 first player  0 not checked  1 second player

ll f(ll a,ll b,ll c){
	if(dp[a][b][c]!=0)
		return dp[a][b][c];
	bool ans=0;
	REP(i,sz(v[a])){
		ll Y=v[a][i].F;
		ll C=v[a][i].S-'a';
		if(C<c)
			continue;
		ans|=(f(b,Y,C)==1);
	}
	if(ans)
		dp[a][b][c]=-1;
	else
		dp[a][b][c]=1;
	return dp[a][b][c];
}

int main(){
	ll n,m;cin>>n>>m;
	REP(i,m){
		ll a,b;
		char c;
		cin>>a>>b>>c;
		a--;b--;
		v[a].PB(MP(b,c));
	}
	REP(i,n){
		REP(j,n)
			cout<<(f(i,j,0)==-1?"A":"B");
		cout<<endl;
	}
}