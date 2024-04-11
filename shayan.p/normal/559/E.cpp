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

const ll maxn=110;

pll p[maxn];
map<ll,ll>cod;
ll dc[3*maxn];
ll dp[maxn][3*maxn];

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>p[i].F>>p[i].S;
	cod[p[i].F]=0;
	cod[p[i].F-p[i].S]=0;
	cod[p[i].F+p[i].S]=0;
    }
    sort(p+1,p+n+1);
    ll h=0;
    for(map<ll,ll>::iterator it=cod.begin();it!=cod.end();it++){
	cod[it->F]=(++h);
	dc[h]=it->F;
    }
    
    FOR(i,1,n){
	FOR(j,1,h){
	    if((p[i].F-p[i].S)>=dc[j]){
		dp[i][j]=dp[i-1][j];
		continue;
	    }
	    ll A=max(ll(0),min(p[i].F+p[i].S,dc[j])-p[i].F)+(p[i].F<dc[j]?dp[i-1][cod[p[i].F]]:dp[i-1][j]);
	    ll B=min(p[i].F,dc[j])-(p[i].F-p[i].S)+dp[i-1][cod[p[i].F-p[i].S]];
	    ll C=0;
	    if(dc[j]>p[i].F){
		ll m=p[i].F-p[i].S;
		FORD(k,i-1,1){
		    m=min(m,p[k].F);
		    if((p[k].F+p[k].S)>p[i].F)
			C=max(C,min(p[k].F+p[k].S,dc[j])-m+dp[k-1][cod[m]]);
		    m=min(m,p[k].F-p[k].S);
		}
	    }
	    dp[i][j]=max(A,max(B,C));
	}
    }
    cout<<dp[n][h];
}