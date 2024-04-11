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

const int maxn=1e5+10,mod=998244353;
const ll inf=1e18;

int fac[maxn],ifac[maxn];

inline int C(int n,int k){
    if(n<k) return 0;
    return 1ll*fac[n] * ifac[k] %mod * ifac[n-k] %mod;
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

    fac[0]=ifac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]=1ll*i*fac[i-1] %mod;
    ifac[maxn-1]=Pow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]=1ll*(i+1)*ifac[i+1] %mod;
    int n,m,k;cin>>n>>m>>k;
    int ans=1ll*C(n-1,k)*m %mod *Pow(m-1,k) %mod;
    cout<<ans<<endl;
    return 0;
}