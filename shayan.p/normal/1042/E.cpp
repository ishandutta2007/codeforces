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

#pragma GCC optimize("Ofast")
#pragma GCC optimize("O5")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const int maxn=1010,MAX=1e6+10;
const ll mod=998244353;

int tavan(int a,int b){
    int ans=1;
    while(b>0){
	if(b&1) ans=(1ll*ans*a)%mod;
	a=(1ll*a*a)%mod;
	b/=2;
    }
    return ans;
}


vector<pii>v[MAX];
int arr[MAX],a[maxn][maxn],C;
int smx,smy,smm,cnt;
pii dp[maxn][maxn],smd;

void operator+=(pii &a,pii b){
    int x=(1ll*a.F*b.S+1ll*b.F*a.S)%mod;
    int y=(1ll*a.S*b.S)%mod;
    a={x,y};
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    REP(i,n){
	REP(j,m){
	    scanf("%d",&a[i][j]);
	    arr[C++]=a[i][j];
	}
    }
    sort(arr,arr+C);
    C=unique(arr,arr+C)-arr;
    
    REP(i,n){
	REP(j,m){
	    a[i][j]=lower_bound(arr,arr+C,a[i][j])-arr;
	    v[a[i][j]].PB({i,j});
	}
    }
    
    smd={0,1};
    REP(w,MAX){
	for(pii p:v[w]){
	    dp[p.F][p.S]=smd;
	    if(cnt==0)continue;
	    pii ad={(smm+1ll*cnt*(p.F*p.F+p.S*p.S)-2ll*p.F*smx-2ll*p.S*smy)%mod,1};
	    dp[p.F][p.S]+=ad;
	    dp[p.F][p.S].S=(1ll*dp[p.F][p.S].S*cnt)%mod;
	}
	cnt+=sz(v[w]);
	for(pii p:v[w]){
	    smm=(1ll*p.F*p.F+1ll*p.S*p.S+smm)%mod;
	    smx=(smx+p.F)%mod;
	    smy=(smy+p.S)%mod;
	    smd+=dp[p.F][p.S];
	}
    }
    int r,c;scanf("%d%d",&r,&c);
    int ans=(1ll*dp[r-1][c-1].F*tavan(dp[r-1][c-1].S,mod-2))%mod;
    if(ans<0)ans+=mod;
    printf("%d\n",ans);
}