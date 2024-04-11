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

const int maxn=2e6 +10,mod=1e9+7;
const ll inf=1e18;

int cnt[maxn], a[maxn];
bool is[maxn];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	int n; cin>>n;
	v.clear();
	
	int mn=n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    cnt[a[i]]++;
	}
	for(int i=0;i<n;i++){
	    if(is[a[i]]==0){
		is[a[i]]=1;
		v.PB(cnt[a[i]]);
		mn=min(mn, cnt[a[i]]);
	    }
	}
	int s=1;
	for(int i=mn;i>=1;i--){
	    for(int j:v){
		if((j/i)<(j%i))
		    goto Hell;
	    }
	    s=i;
	    break;
	Hell:;
	}
	int ans=0;
	for(int x:v){
	    ans+= (x/s) - (((x/s)-(x%s))/(s+1));
	}
	cout<<ans<<"\n";

	for(int i=0;i<n;i++){
	    is[a[i]]=0;
	    cnt[a[i]]=0;
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")