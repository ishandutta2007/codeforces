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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxnum=1e5+10;

bool act[maxnum];
bool prime[maxnum];
bool good[maxnum];
ll count_num[maxnum];
ll cnt[maxnum];
ll tw[maxnum];

int main(){
	fill(good,good+maxnum,1);
	//act[1]=0
	for(ll i=2;i<maxnum;i++){
		if(!prime[i]){//is prime
			for(ll j=i /*not 2*i*/;j<maxnum;j+=i){
				act[j]=!act[j];
				prime[j]=1;
				if((j/i)%i==0)
					good[j]=0;
			}
		}
	}
	
	tw[0]=1;
	for(ll i=1;i<maxnum;i++)
		tw[i]=(tw[i-1]*2)%mod;
	
	ll n;cin>>n;
	REP(i,n){
		ll x;cin>>x;
		count_num[x]++;
	}
	
	for(ll i=1;i<maxnum;i++){
		for(ll j=i;j<maxnum;j+=i){
			cnt[i]+=count_num[j];
		}
	}
	
	ll ans=0;
	FOR(i,1,maxnum){
		if(!good[i])continue;
		ans+=(act[i]==0?1:-1)*(tw[cnt[i]]-1);
		ans%=mod;
		ans=(ans+mod)%mod;
	}
	cout<<ans;
	return 0;
}