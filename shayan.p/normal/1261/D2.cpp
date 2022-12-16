// Remember...

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

const int maxn=2e5+10,mod=998244353;
const ll inf=1e18;

int a[maxn], fac[maxn], ifac[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1, a=1ll*a*a %mod){
	if(b&1) ans=1ll*ans*a %mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]= 1ll*i*fac[i-1] %mod;
    ifac[maxn-1]= Pow(fac[maxn-1], mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]= 1ll*ifac[i+1] * (i+1) %mod;

    int n,k; cin>>n>>k;

    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    if(k==1) return cout<<0<<endl,0;
    
    int z=0;
    for(int i=0;i<n;i++){
	if(a[i] != a[(i +1) %n])
	    z++;
    }
    int ans=0;
    for(int i=(z&1);i<=z;i+=2){
	ans=( 1ll*ans + 1ll*Pow(k-2,i)*fac[z] %mod * ifac[i] %mod * ifac[(z-i)/2] %mod * ifac[(z-i)/2] ) %mod;
    }
    ans=1ll*ans*Pow(k,n-z) %mod;
    ans=(Pow(k,n)-ans) %mod;
    ans=1ll*ans * Pow(2,mod-2) %mod;
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")