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

const int maxn=1e6 +10 ,mod=998244353;
const ll inf=1e18;

int fac[maxn], ifac[maxn], sm1[maxn], sm2[maxn];

int Pow(int a,int b){
    int ans=1;
    for(; b; b>>=1, a=1ll*a*a %mod)
	if(b&1)
	    ans=1ll*ans*a %mod;
    return ans;
}

int C(int n,int k){
    if(n<0 || k<0 || n<k) return 0;
    return 1ll* fac[n] * ifac[k] %mod * ifac[n-k] %mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0]=1;
    for(int i=1; i<maxn; i++)
	fac[i]= 1ll*i *fac[i-1] %mod;
    ifac[maxn-1]= Pow(fac[maxn-1], mod-2);
    for(int i=maxn-2; i>=0; i--)
	ifac[i] = 1ll*ifac[i+1] * (i+1) %mod;

    string s; cin>>s;
    int n=sz(s);

    int cls=0, qus=0;
    for(int i=0; i<sz(s); i++){
	qus+= s[i]=='?';
	cls+= s[i]==')';
    }
    for(int i=n; i>=0; i--){
	sm1[i] = ( sm1[i+1] + C(qus, i) ) %mod;
	sm2[i] = ( sm2[i+1] + C(qus-1, i) ) %mod;
    }
    int ans=0;
    for(int i=0; i<sz(s); i++){
	if(s[i] == '?')
	    ans = ( ans + sm2[ max(0, i+1-cls ) ] ) %mod; 
	if(s[i] == '(')
	    ans = ( ans + sm1[ max(0, i+1-cls ) ] ) %mod;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")