// only miss the sun when it starts to snow

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn];
set<pll> dp;

void add(ll a,ll b){
    auto it=dp.upper_bound({a,-1});
    if(it == dp.end() ){
	dp.insert({a,b});
	return;
    }
    if((it->S)  >= b) return;
    if((it->F) == a) dp.erase(it);
    
    dp.insert({a,b});
    it= dp.find({a,b});

    while(it != dp.begin() && (prev(it)->S) <= b)
	dp.erase(prev(it));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n; cin>>n;

    for(int i=0;i<n;i++){
	cin>>a[i];
	if(i!=0 && a[i-1]<a[i]) a[i]=a[i-1];
    }
    a[n++]=1;

    dp.insert({a[0]-1,0});

    for(int i=1;i<n;i++){
	ll num=0;
	auto it=dp.rbegin();
	while( (it->F) >= a[i] ){
	    ll x= (it->F)/a[i];

	    num= max(num, (it->S) + (x-1)*a[i]*i ), add( (it->F)%a[i], (it->S) + x*a[i]*i );

	    dp.erase(*it), it=dp.rbegin();
	}
	add(a[i]-1, num);
    }
    return cout<<(dp.begin()->S)<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")