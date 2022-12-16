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

const int maxn=1e5+10,mod=1e9+9;
const ll inf=1e18;

ll Pow(ll a,ll b){
    ll ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b/=2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a,b,k;cin>>n>>a>>b>>k;
    string s;cin>>s;
    ll A=0,B=1ll*Pow(b,k)*Pow(a,mod-1-k) %mod;
    B=1ll*(Pow(B,(n+1)/k)-1)*Pow(B-1,mod-2) %mod;
    for(ll i=0;i<k;i++)
	A=(1ll*A+1ll*(s[i]=='+'?1:-1)*Pow(a,n-i)*Pow(b,i))%mod;
    if(B==0) A=1ll*A*((n+1)/k) %mod;
    else A=1ll*A*B %mod;
    if(A<0) A+=mod;
    cout<<A<<endl;
    return 0;
}