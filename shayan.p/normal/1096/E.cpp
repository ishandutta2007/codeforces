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

const int maxn=110,maxs=5111,mod=998244353;

int C[maxs][maxs];

inline int solve_eq(int n,int s){
    if(s<0) return 0;
    if(n==0 && s==0) exit(0);
    return C[n+s-1][s];
}

inline int solve_eq2(int n,int s,int lim){
    if(n==0) return s==0;
    int ans=0;
    for(int i=0;i*lim<=s && i<=n;i++)
	ans=(1ll*ans+1ll*(i&1?-1:1)*C[n][i]*solve_eq(n,s-lim*i))%mod;
    if(ans<0) ans+=mod;
    return ans;
}

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<maxs;i++){
	C[i][0]=C[i][i]=1;
	for(int j=1;j<i;j++)
	    C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    int n,s,r;cin>>n>>s>>r;
    int ans=0;
    for(int i=1;i<=n;i++)
	for(int lim=r;i*lim<=s;lim++)
	    ans=(1ll*Pow(i,mod-2)*C[n-1][i-1] %mod *solve_eq2(n-i,s-lim*i,lim) %mod +1ll*ans)%mod;
    ans=1ll*ans*Pow(solve_eq(n,s-r),mod-2) %mod;
    return cout<<ans<<endl,0;
}