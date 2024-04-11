// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll tavan(ll a,ll b){
    ll ans=1;
    while(b>0){
	if(b%2)ans=(ans*a)%mod;
	a=(a*a)%mod;
	b/=2;
    }
    return ans;
}
int main(){
    ll x,k;cin>>x>>k;
    if(x==0){
	cout<<0;
	return 0;
    }
    x%=mod;
    ll ans=(tavan(2,k+1)*x)-tavan(2,k)+1;
    ans=((ans%mod)+mod)%mod;
    cout<<ans;
}