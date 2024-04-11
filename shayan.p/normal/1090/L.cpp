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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,a,b,k;cin>>t>>n>>a>>b>>k;
    int na=(n+1)/2,nb=n-na;
    if(a>b) swap(a,b),swap(na,nb);
    if(k>n) return cout<<0<<endl,0;
    ll ans;
    if(k<=nb || ((1ll*na*a)/(k-nb))>=b)
	ans=min(ll(t),(1ll*a*na+1ll*b*nb)/k);
    else
	ans=min(ll(t),(1ll*a*na)/(k-nb));
    cout<<ans<<endl;
    return 0;
}