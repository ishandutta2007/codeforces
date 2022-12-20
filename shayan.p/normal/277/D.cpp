// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef pair<ld,ld> pld;

const int maxn=1600;
const ld eps=1e-10;

pld dp[maxn][maxn];

struct problem{
    ll sc1,sc2,t1,t2;
    ld p;
};problem prob[maxn];

inline bool CMP(problem a,problem b){
    return a.p * a.t2 * (1-b.p) < b.p * b.t2 * (1-a.p);
}

pld Max(pld a,pld b){
    if(a.F>b.F+eps) return a;
    if(b.F>a.F+eps) return b;
    if(a.S>b.S) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,t;cin>>n>>t;
    for(int i=1;i<=n;i++){
	cin>>prob[i].sc1>>prob[i].sc2>>prob[i].t1>>prob[i].t2>>prob[i].p;
    }
    sort(prob+1,prob+n+1,CMP);
    for(int i=1;i<=n;i++){
	for(int j=0;j<=t;j++){
	    pld A={0,0},B={0,0},DP={0,0};
	    problem &x=prob[i];
	    if(j>=x.t1) DP=dp[i-1][j-x.t1],A={DP.F+x.sc1,DP.S};
	    if(j>=x.t1+x.t2) DP=dp[i-1][j-x.t1-x.t2],B={DP.F+x.sc1+x.sc2*(1-x.p),(DP.S+x.t2)*x.p};
	    dp[i][j]=Max(dp[i-1][j],Max(A,B));
	}
    }
    pld ans={0,0};
    for(int i=0;i<=t;i++){
	dp[n][i].S=dp[n][i].S-i;
	ans=Max(ans,dp[n][i]);
    }
    cout<<setprecision(15)<<fixed<<ans.F<<" "<<-ans.S<<endl;
    return 0;
}