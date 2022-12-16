// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define bit(num,i) ((num>>i)&1)

#pragma GCC Optimize("Ofast")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=1e3+10;

string s;
ll k;
ll num[maxn];
ll ones;
ll fac[maxn],ifac[maxn];
ll inv[maxn];

void prep(){
    fac[0]=ifac[0]=inv[1]=1;
    for(ll i=1;i<maxn;i++)
        fac[i]=(i*fac[i-1])%mod;
    for(ll i=2;i<maxn;i++) 
        inv[i]=mod-1LL*(mod/i)*inv[mod%i]%mod;
    for(ll i=1;i<maxn;i++)
        ifac[i]=(inv[i]*ifac[i-1])%mod;
}

inline ll C(ll a,ll b){
	if(b>a) return 0;
	return (((fac[a]*ifac[b])%mod)*ifac[a-b])%mod;
}

ll calc(ll val){
	ll ans=0;
	if(val==1)ans--;
	if(ones==val)ans++;
	
	REP(i,sz(s)){
		if(s[i]=='1'){
			ll ret=sz(s)-i-1;
			ans+=C(ret,val);
			ans%=mod;
			if(val--==0)
				break;
		}
	}
	return ans;
}

int main(){
	prep();
	
	cin>>s>>k;
	
	if(k==0){
		cout<<1;
		return 0;
	}
	
	REP(i,sz(s))
		ones+=(s[i]=='1');
		
	ll ans=0;
	num[1]=-1;
	FOR(i,1,maxn-1){
		ll cop=i;
		ll cnt=0;
		while(cop>0){
			cnt+=cop%2;
			cop/=2;
		}
		num[i]=1+num[cnt];
		if(num[i]==k-1){
			ans+=calc(i);
			ans%=mod;
		}
	}
	cout<<ans;
}