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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn], arr[maxn];
pii p[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;

    while(q--){
	int n; cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    arr[i]= a[i];
	}
	sort(arr,arr+n);
	int C= unique(arr,arr+n) - arr;
	for(int i=0;i<C;i++){
	    p[i].S= -1;
	}
	for(int i=0;i<n;i++){
	    a[i]= lower_bound(arr,arr+C,a[i])-arr;
	    if(p[ a[i] ].S==-1) p[ a[i] ].F=i;
	    p[ a[i] ].S=i;
	}
	int ans=0;
	for(int l=0,r=0; l<C; l=r+1){
	    r=l;
	    while(r<C-1 && p[r].S<p[r+1].F) r++;
	    ans=max(ans, r-l+1);
	}
	cout<<C-ans<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")