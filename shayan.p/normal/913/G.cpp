
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

ll tn[20],fv[20];

ll Mul(ll a,ll b,ll md){
    ll ans=0;
    while(b){
	if(b&1) ans=(ans+a)%md;
	a=(a+a)%md;
	b>>=1;
    }
    return ans;
}

ll Pow(ll a,ll b,ll md){
    ll ans=1;
    while(b){
	if(b&1) ans=Mul(ans,a,md);
	a=Mul(a,a,md);
	b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    tn[0]=fv[0]=1;
    for(int i=1;i<19;i++)
	tn[i]=tn[i-1]*10,fv[i]=fv[i-1]*5;
    int q;cin>>q;
    while(q--){
	ll x;cin>>x;
	ll xx=x;int n=0;
	while(xx>0) n++,xx/=10;
	ll y=(-tn[17-n]*x)%(1ll<<17);
	if(y<0) y+=(1ll<<17);
	if(y%5==0) y+=(1ll<<17);
	x=tn[17-n]*x+y;
	ll ans=0;
	if(x%5==2) ans=1;
	if(x%5==4) ans=2;
	if(x%5==3) ans=3;
	for(int i=2;i<=17;i++)
	    while(Pow(2,ans,fv[i])!=(x%fv[i]))
		ans=(ans+4ll*fv[i-2])%(4ll*fv[i-1]);
	ans+=4ll*fv[16];
	cout<<ans<<"\n";
    }
}