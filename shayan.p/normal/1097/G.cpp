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

const int maxn=2e5+10,maxk=210,mod=1e9+7;

vector<int>v[maxn],dp1[maxn],dp2[maxn],vv;
int n,k;

void operator * (vector<int>&a,vector<int>&b){
    vv.clear();vv.resize(k+1);
    for(int i=0;i<sz(a);i++)
	for(int j=0;j<sz(b) && i+j<=k;j++)
	    vv[i+j]=(1ll*vv[i+j]+1ll*a[i]*b[j])%mod;
    while(vv.back()==0) vv.pop_back();
}
void operator ++ (vector<int>&a){
    int num=a.back();
    for(int i=sz(a)-1;i>0;i--)
	a[i]=(a[i]+a[i-1])%mod;
    if(sz(a)<=k) a.PB(num);
}
void operator -- (vector<int>&a){
    for(int i=1;i<sz(a);i++)
	a[i]=(a[i]-a[i-1])%mod;
}
void operator += (vector<int>&a,vector<int>&b){
    a.resize(max(sz(a),sz(b)));
    for(int i=0;i<sz(a);i++)
	a[i]=(a[i]+(i>=sz(b)?0:b[i]))%mod;
}

void dfs(int u,int par=-1){
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	}
    }
    dp1[u].PB(1);
    dp2[u].PB(1);dp2[u].PB(1);
    for(int y:v[u]){
	if(y!=par){
	    dp2[u]*dp2[y];
	    ++dp2[y];
	    dp2[u]+=dp2[y],dp2[u]+=vv;
	    --vv;
	    dp1[u]+=dp1[y],dp1[u]+=vv;
	}
    }
}

int dp[maxk][maxk],fac[maxk];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    dp[0][0]=1;
    for(int i=1;i<maxk;i++){
	for(int j=1;j<=i;j++)
	    dp[i][j]=(1ll*dp[i-1][j]*j+dp[i-1][j-1])%mod;
    }
    fac[0]=1;
    for(int i=1;i<maxk;i++){
	fac[i]=1ll*fac[i-1]*i %mod;
    }
    int Ans=0;
    for(int i=0;i<min(k+1,sz(dp1[1]));i++){
	Ans=(1ll*dp1[1][i]*dp[k][i] %mod *fac[i] + 1ll*Ans)%mod;
    }
    if(Ans<0) Ans+=mod;
    return cout<<Ans<<endl,0;
}