// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=1e4,mod=1e9+7;
const ll inf=1e17;

int dp[maxn],tmp[maxn];
unordered_map<ll,int>fnd;
map<ll,vector<ll> >mp;
vector<ll>vec;

bool prime(ll x){
    if(x<2) return 0;
    for(ll i=2;i*i<=x;i++){
	if(x%i==0)
	    return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll A;cin>>A;
    for(ll i=1;i*i<=A;i++){
	if(A%i==0){
	    fnd[i]=sz(vec);
	    vec.PB(i);
	}
    }
    for(int i=sz(vec)-1;i>=0;i--){
	if(vec[i]*vec[i]==A) continue;
	fnd[A/vec[i]]=sz(vec);
	vec.PB(A/vec[i]);
    }
    for(ll x:vec){
	if(prime(x-1)){
	    mp[x-1].PB(x);
	}
    } 
    for(ll i=2;i*i<=A;i++){
	if(prime(i)){
	    for(ll j=i;j<A;j*=i){
		if(A%(j+1)==0)
		    mp[i].PB(j+1);
	    }
	}
    }
    dp[0]=1;
    for(auto &IT:mp){
	vector<ll>&vv=IT.S;
	sort(vv.begin(),vv.end());
	vv.resize(unique(vv.begin(),vv.end())-vv.begin());
	memcpy(tmp,dp,sizeof dp);
	for(ll x:vec){
	    for(ll y:vv){
		if((inf/x)>y && x*y<=A && A%(x*y)==0){
		    int &num=tmp[fnd[x*y]];
		    num=(num+dp[fnd[x]])%mod;
		}
	    }
	}
	memcpy(dp,tmp,sizeof dp);
    }
    return cout<<dp[fnd[A]]<<"\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.