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

ll Mul(ll a,ll b,ll md){
    ll ans=0;
    while(b){
	if(b&1) ans=(ans+a)%md;
	a=(a+a)%md;
	b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	ll a,b,c;
	cin>>a>>b>>c;
	ll g=__gcd(a,b);
	a/=g;b/=g;
	for(int i=0;i<6;i++)
	    c=Mul(c,c,b);
	cout<<(c==0?"Finite\n":"Infinite\n");
    }
}