// Remember...

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

int a[maxn], b[maxn];
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,h=1; cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i]>>b[i];
	h=max(h, min(a[i],b[i]));
    }
    int ans=1e9;
    for(;h<=1000;h++){
	int cnt=n/2, sm=0;
	vec.clear();
	for(int i=0;i<n;i++){
	    sm+=a[i];
	    if(a[i]>h || b[i]>h){
		if(b[i]>h)
		    cnt--, sm-=a[i], sm+= b[i];		    
	    }
	    else{
		vec.PB(b[i]-a[i]);
	    }
	}
	sort(vec.begin(), vec.end());
	if(cnt<0) continue;
	for(int i=0;i<min(sz(vec),cnt);i++){
	    if(vec[i]>0) break;
	    sm+= vec[i];
	}
	ans=min(ans, sm * h);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")