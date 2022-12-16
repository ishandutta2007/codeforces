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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn], sm[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	int n; cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    a[i]/=100;
	}
	sort(a,a+n,greater<ll>());
	for(int i=0;i<n;i++){
	    sm[i+1]= sm[i] + a[i];
	}
	ll x,a; cin>>x>>a;
	ll y,b; cin>>y>>b;
	ll k; cin>>k;

	if(x<y) swap(x,y), swap(a,b);
	
	int ans=-1;
	for(int i=0;i<=n;i++){
	    ll cnt1= i/ (1ll*a*b / __gcd(a,b));
	    ll cnt2= (i/a) - cnt1;
	    ll cnt3= (i/b) - cnt1;
	    ll num= sm[cnt1] * (x+y) + (sm[cnt2+cnt1]-sm[cnt1]) * x + (sm[cnt1 + cnt2 + cnt3] - sm[cnt2+cnt1]) *y;
	    if(num >= k){
		ans=i;
		break;
	    }
	}
	cout<<ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")