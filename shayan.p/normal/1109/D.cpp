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

const int maxn=2e6+10,mod=1e9+7;
const ll inf=1e18;

int fac[maxn],ifac[maxn],pw[maxn],pwm[maxn];

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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]=1ll*i*fac[i-1] %mod;
    ifac[maxn-1]=Pow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]=1ll*(i+1)*ifac[i+1] %mod;
    int n,m,tmp,ans=0;cin>>n>>m>>tmp>>tmp;
    pw[0]=pwm[0]=1;
    for(int i=1;i<maxn;i++)
	pw[i]=1ll*pw[i-1]*n %mod, pwm[i]=1ll*pwm[i-1]*m %mod;
    for(int i=2;i<n;i++)
	ans=(1ll*ans+1ll*C(n-2,i-2)*C(m-1,i-2) %mod *fac[i-2] %mod * i %mod * pw[n-i-1] %mod *pwm[n-i])%mod;
    ans=(1ll*ans+1ll*fac[n-2]*C(m-1,n-2))%mod;
    return cout<<ans<<endl,0;
}