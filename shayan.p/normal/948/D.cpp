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

using namespace std;
typedef long long ll;/////////////////////////////int
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=3e5+10;
const ll mod=1e9+7;
const ll MAX=1e7;

#pragma GCC Optimize("Ofast")

ll trie[MAX][2];
ll cnt[MAX];
ll t;

void add(ll num){
	ll now=0;
	cnt[0]++;
	REPD(i,30){
		bool bt=bit(num,i);
		if(trie[now][bt]==0)
			trie[now][bt]=++t;
		now=trie[now][bt];
		cnt[now]++;
	}
}

ll ask(ll num){
	cnt[0]--;
	ll ans=0,now=0;
	REPD(i,30){
		bool bt=bit(num,i);
		if(trie[now][bt]==0||cnt[trie[now][bt]]==0)
			bt^=1;
		now=trie[now][bt];
		cnt[now]--;
		ans+=(1<<i)*bt;
	}
	return ans;
}

ll a[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n){
		cin>>a[i];
	}
	REP(i,n){
		ll x;cin>>x;
		add(x);
	}
	REP(i,n){
		cout<<(a[i]^ask(a[i]))<<" ";
	}
}