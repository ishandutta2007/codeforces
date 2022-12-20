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

string s;
ll dp[maxn][maxn],pos[maxn][maxn];
ll cost[maxn][maxn];

vector<string>ans;

string handle(ll l,ll r){
    FOR(i,l,r){
	if(s[i]!=s[l+r-i])
	    s[i]=s[l+r-i];
    }
    return s.substr(l,r-l+1);
}

int main(){
    cin>>s;
    ll k;cin>>k;
    FOR(r,0,sz(s)-1){
	FORD(l,r-1,0){
	    cost[l][r]=cost[l+1][r-1]+(s[l]!=s[r]);
	}
    }
    REP(i,sz(s)){
	dp[i][1]=cost[0][i];
	pos[i][1]=-1;
	FOR(j,2,k){
	    dp[i][j]=inf;
	    REP(w,i){
		if((dp[w][j-1]+cost[w+1][i])<dp[i][j]){
		    dp[i][j]=dp[w][j-1]+cost[w+1][i];
		    pos[i][j]=w;
		}
	    }
	}
    }
    ll pr=1;
    FOR(i,1,k){
	if(dp[sz(s)-1][i]<dp[sz(s)-1][pr])
	    pr=i;
    }

    ll ind=sz(s)-1;
    FORD(i,pr,1){
	ans.PB(handle(pos[ind][i]+1,ind));
	ind=pos[ind][i];
    }

    cout<<dp[sz(s)-1][pr]<<endl;
    
    REPD(i,pr){
	if(i!=(pr-1))
	    cout<<'+';
	cout<<ans[i];
    }
}