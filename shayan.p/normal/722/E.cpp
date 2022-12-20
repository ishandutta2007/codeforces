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

const ll MAX=2e5+10;
const ll maxn=2010;
const ll mod=1e9+7;

ll dp[maxn][31];
pll p[maxn];
bool b1,b2;

ll fac[MAX],ifac[MAX];

ll tavan(ll a,ll b){
    ll ans=1;
    while(b>0){
	if(b%2) ans=(ans*a)%mod;
	a=(a*a)%mod;
	b/=2;
    }
    return ans;
}
inline ll C(ll a,ll b){
    if(a<b)return 0;
    return (((fac[a]*ifac[b])%mod)*ifac[a-b])%mod;
}

int main(){
    fac[0]=1;
    FOR(i,1,MAX-1){
	fac[i]=(i*fac[i-1])%mod;
    }
    ifac[MAX-1]=tavan(fac[MAX-1],mod-2);
    FORD(i,MAX-2,0){
	ifac[i]=((i+1)*ifac[i+1])%mod;
    }
    
    ll n,m,k,s;cin>>n>>m>>k>>s;
    REP(i,k){
	cin>>p[i].F>>p[i].S;
	b1|=(p[i].F==1 && p[i].S==1);
	b2|=(p[i].F==n && p[i].S==m);
    }
    if(!b1)p[k++]={1,1};
    if(!b2)p[k++]={n,m};

    sort(p,p+k);
    
    dp[0][1]=1;
    FOR(i,1,k-1){
	FOR(j,1,29){
	    dp[i][j]=C(p[i].F+p[i].S-2,p[i].F-1);
	    REP(w,i){
		if(p[w].S<=p[i].S)
		    dp[i][j]=(dp[i][j]-dp[w][j]*C(p[i].F+p[i].S-p[w].F-p[w].S,p[i].F-p[w].F))%mod;
	    }
	}
	FORD(j,29,1){
	    dp[i][j]=(dp[i][j]-dp[i][j-1])%mod;
	}
    }
    dp[k-1][30]=C(n+m-2,n-1);
    REP(i,30){
	dp[k-1][30]=(dp[k-1][30]-dp[k-1][i])%mod;
    }
    
    ll cnt=2-(b1+b2),A=0;
    FOR(i,cnt,30){
	dp[k-1][30]+=mod;
	A=(A+s*dp[k-1][i])%mod;
	s=(s/2)+(s%2);
    }

    cout<<(A*tavan(C(n+m-2,n-1),mod-2))%mod;
}