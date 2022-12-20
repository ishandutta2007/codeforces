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

const int maxn=110,mod=1e9+7;
const ll inf=1e18;

int SZ[maxn],ans[maxn],dp[maxn][maxn][maxn],tmp[maxn][maxn];// root // edges // vertices in root component
int fac[maxn],ifac[maxn],inv[maxn];
vector<int> v[maxn];

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

inline int C(int n,int k){
    if(n<k) return 0;
    return 1ll*fac[n]*ifac[k] %mod *ifac[n-k] %mod;
}

void dfs(int u,int par=-1){// calculating dp
    for(int y:v[u]){
	if(y!=par)
	    dfs(y,u);
    }
    SZ[u]=1;
    dp[u][0][1]=1;
    for(int y:v[u]){
	if(y!=par){// tmp should become 0
	    for(int i=0;i<=SZ[u]+SZ[y];i++){
		for(int j=0;j<=SZ[u]+SZ[y];j++){
		    tmp[i][j]=0;
		}
	    }
	    for(int i=0;i<SZ[u];i++){
		for(int j=0;j<SZ[y];j++){
		    for(int A=0;A<=SZ[u];A++){
			for(int B=0;B<=SZ[y];B++){
			    tmp[i+j][A]=(1ll*tmp[i+j][A]+1ll*dp[u][i][A]*dp[y][j][B])%mod;
			    tmp[i+j+1][A+B]=(1ll*tmp[i+j+1][A+B]+1ll*dp[u][i][A]*dp[y][j][B] %mod * inv[A] %mod *inv[B] %mod *(A+B) )%mod;
			}
		    }
		}
	    }
	    SZ[u]+=SZ[y];
	    for(int i=0;i<SZ[u];i++){
		for(int j=0;j<=SZ[u];j++){
		    dp[u][i][j]=tmp[i][j];
		}
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fac[0]=ifac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]=1ll*i*fac[i-1] %mod,ifac[i]=Pow(fac[i],mod-2),inv[i]=Pow(i,mod-2);
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    ans[n-1]=1;
    for(int i=0;i<n-1;i++){
	for(int j=0;j<=n;j++)
	    ans[i]=(ans[i]+dp[1][i][j])%mod;
    }
    for(int i=n-2;i>=0;i--){
	ans[i]=1ll*ans[i]*Pow(n,n-i-2) %mod;
	for(int j=i+1;j<n;j++)
	    ans[i]=(1ll*ans[i]-1ll*ans[j]*C(j,i))%mod;
    }
    for(int i=0;i<n;i++){
	ans[i]=(ans[i]+mod)%mod;
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}