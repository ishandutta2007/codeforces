// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=60,mod=1e9+7;

int dp[maxn][maxn][maxn],tw[maxn];

void upd(int ln,int c){
    if(c==0){
	for(int i=0;i<maxn;i++){
	    for(int j=0;j<maxn;j++){
		dp[ln][i][j]=(1ll*dp[ln][i][j]+1ll*dp[ln-1][i][j]*(j==0?0:tw[ln-2])+1ll*(i==0?0:(1ll*dp[ln-1][i-1][j]*(j==0?tw[ln-1]:tw[ln-2]))))%mod;
	    }
	}
    }
    else{
	for(int i=0;i<maxn;i++){
	    for(int j=0;j<maxn;j++){
		dp[ln][i][j]=(1ll*dp[ln][i][j]+1ll*dp[ln-1][i][j]*(i==0?0:tw[ln-2])+1ll*(j==0?0:(1ll*dp[ln-1][i][j-1]*(i==0?tw[ln-1]:tw[ln-2]))))%mod;
	    }
	}
    }
}

int main(){
    tw[0]=1;
    for(int i=1;i<maxn;i++){
	tw[i]=(2*tw[i-1])%mod;
    }
    
    int n,p;scanf("%d%d",&n,&p);
    
    int c;scanf("%d",&c);
    if(c==-1)
	dp[1][0][1]=dp[1][1][0]=1;
    if(c==0)
	dp[1][1][0]=1;
    if(c==1)
	dp[1][0][1]=1;
    
    for(int i=2;i<=n;i++){
	int c;scanf("%d",&c);
	if(c==-1)
	    upd(i,0),upd(i,1);
	else
	    upd(i,c);
    }

    int ans=0;
    for(int i=0;i<maxn;i++){
	for(int j=0;j<maxn;j++){
	    if(((i+j)&1) == p)
		ans=(ans+dp[n][i][j])%mod;
	}
    }

    printf("%d\n",ans);
}