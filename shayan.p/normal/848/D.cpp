// Wanna Hack? GL...

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

const int maxn=55,mod=1e9+7;
const ll inf=1e18;

int mat[maxn][maxn],tmp[maxn][maxn],dp[maxn][maxn];
int ifac[maxn];

vector<pair<pii,int> >vec;

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

int f(int n,int k){
    if(k==0) return 1;
    if(n==0) return 0;
    n+=k-1;
    int ans=1;
    for(int i=0;i<k;i++){
	ans=1ll*ans*(n-i) %mod;
    }
    return 1ll*ans*ifac[k] %mod;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    ifac[0]=1;
    for(int i=1;i<maxn;i++)
	ifac[i]=1ll*ifac[i-1]*Pow(i,mod-2) %mod;
    
    int n,m;cin>>n>>m;

    dp[0][0]=mat[0][0]=1;
    for(int i=1;i<=n;i++){
	for(int j=1;j<=n+1;j++){
	    for(int k=0;k<i;k++){
		int sm=0;
		for(int w=j;w<=n+1;w++)
		    sm=(sm+mat[i-1-k][w-1])%mod;
		dp[i][j]=(1ll*dp[i][j]+2ll*mat[k][j-1]*sm-1ll*mat[k][j-1]*mat[i-1-k][j-1])%mod;
	    }
	    //	    cout<<"HEY "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	    vec.clear();
	    for(int I=0,J=0;I<maxn && J<maxn;I+=i,J+=j){
		//		if(i==2 && j==1) cout<<"HELLO "<<f(dp[i][j],I/i)<<endl;
		vec.PB({{I,J},f(dp[i][j],I/i)});
	    }
	    for(int x=0;x<maxn;x++){
		for(int y=0;y<maxn;y++){
		    tmp[x][y]=0;
		    for(auto X:vec){
			//			if(x==2 && y==1 && X.F.F==2 && X.F.S==1)
			//			    cout<<"SHOOOOOOOOOOOOOOOOOOOOOOOT "<<mat[x-X.F.F][y-X.F.S]<<" "<<X.S<<endl;
			if(x-X.F.F>=0 && y-X.F.S>=0)
			    tmp[x][y]=(1ll*tmp[x][y]+1ll*mat[x-X.F.F][y-X.F.S]*X.S)%mod;
		    }		    
		}
	    }
	    for(int x=0;x<maxn;x++){
		for(int y=0;y<maxn;y++){
		    mat[x][y]=tmp[x][y];
		}
	    }
	}
    }
    int ans=mat[n][m-1];
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}