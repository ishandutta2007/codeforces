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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

ll solve(ll n,ll p){
    ll ans=0;
    while(n){
	n/=p;
	ans+=n;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,b,ans=inf;cin>>n>>b;
    for(ll i=2;i*i<=b;i++){
	if(b%i==0){
	    int cnt=0;
	    while(b%i==0) b/=i,cnt++;
	    ans=min(ans,solve(n,i)/cnt);
	}
    }
    if(b>1) ans=min(ans,solve(n,b));
    return cout<<ans<<endl,0;
}