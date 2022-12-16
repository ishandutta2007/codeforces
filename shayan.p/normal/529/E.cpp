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

const int maxn=5010, MAXN=1e7 + 10;

int ans[40], qr[40], v[maxn];
bool is[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,k; cin>>n>>k;
    for(int i=0;i<n;i++)
	cin>>v[i], is[v[i]]=1;
    int q; cin>>q;
    while(q--){
	int x; cin>>x;
	int ans=k+1;
	for(int a=1;a<=k;a++){
	    for(int b=1;a+b<=k;b++){
		for(int i=0;i<n;i++){
		    int num= x - a*v[i];
		    if(num>=0 && num%b==0 && (num/b)<MAXN && is[num/b]) ans=min(ans, a+b);
		}
	    }
	}
	for(int a=1;a<=k;a++){
	    if(x%a==0 && (x/a)<MAXN && is[x/a]) ans=min(ans,a);
	}
	if(ans==k+1) ans=-1;
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