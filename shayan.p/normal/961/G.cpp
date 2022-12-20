// Can U hack it?

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

const int maxn=2e5+10,mod=1e9+7;

int fac[maxn],ifac[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b>0;b/=2){
	if(b&1) ans=(1ll*ans*a)%mod;
	a=(1ll*a*a)%mod;
    }
    return ans;
}

int C(int n,int k){
    if(n<k)return 0;
    return 1ll*fac[n]*ifac[k] %mod *ifac[n-k] %mod;
}

int strling(int n,int k){
    int ans=0;
    for(int i=0;i<k;i++)
	ans=(ans+1ll*(i&1?-1:1)*Pow(k-i,n)*C(k,i))%mod;
    ans=(1ll*ans*ifac[k])%mod;
    return ans;
}

int f(int n,int k){
    return strling(n,k)+1ll*(n-1)*strling(n-1,k) %mod;
}

void pre(){
    fac[0]=ifac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]=1ll*i*fac[i-1] %mod;
    ifac[maxn-1]=Pow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]=1ll*ifac[i+1]*(i+1) %mod;
}

int main(){
    pre();
    int n,k,ans=0;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
	int x;scanf("%d",&x);
	ans=(ans+x)%mod;
    }
    ans=(1ll*ans*f(n,k))%mod;
    if(ans<0)ans+=mod;
    printf("%d\n",ans);
}