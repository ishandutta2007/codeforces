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

const int maxn=210;

ll dp[maxn][maxn],sm[maxn][maxn],C[maxn][maxn];// size akidan ziresh // darjeeash

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,d,m;cin>>n>>d>>m;

    if(d==1){
	if(n==2)
	    return cout<<4%m<<endl,0;
	else
	    return cout<<0<<endl,0;
    }
    C[0][0]=1;
    for(int i=1;i<maxn;i++){
	C[i][0]=1;
	for(int j=1;j<=i;j++){
	    C[i][j]=(C[i-1][j]+C[i-1][j-1])%m;
	}
    }

    dp[0][0]=sm[0][0]=1;
    for(int j=1;j<=d;j++){
	sm[0][j]=1;
    }
    for(int i=1;i<maxn;i++){
	for(int j=1;j<=d;j++){
	    for(int k=1;k<=i;k++){
		dp[i][j]=(dp[i][j]+dp[i-k][j-1]*sm[k-1][d-1] %m *C[i-1][k-1]) %m;
	    }
	    sm[i][j]=(sm[i][j-1]+dp[i][j])%m;
	}
    }

    ll ans=0;
    for(int i=0;i<n;i++){
	for(int j=0;(j+i)<n-1;j++){
	    ans=(ans+(sm[i][d-1]-dp[i][1])*(sm[j][d-1]-dp[j][1]))%m;
	}
    }
    for(int i=0;i<n;i++){
	for(int dg=0;dg<=d;dg++){
	    if(dg==1) continue;
	    ans=(ans+dp[i][dg]*sm[n-1-i][d-dg])%m;
	    if(d-dg>=1)
		ans=(ans-dp[i][dg]*dp[n-1-i][1])%m;
	}
    }
    ans=ans*2*n*(n-1) %m;
    if(ans<0) ans+=m;
    cout<<ans<<endl;
    return 0;
}