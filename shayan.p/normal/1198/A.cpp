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

const int maxn=4e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn];
map<int,int> mp;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,x; cin>>n>>x;

    x=8*x / n;
    x=min(x,20);
    x=1<<x;
	 
    for(int i=0;i<n;i++)
	cin>>a[i];
    sort(a,a+n);

    int pt=0, ans=n;
    
    for(int i=0;i<n;i++){
	while(pt<n && sz(mp)<=x) mp[a[pt]]++, pt++;
	ans=min(ans, i + n-pt +1 - (sz(mp)<=x) );
	if(--mp[a[i]] == 0) mp.erase(a[i]);

	//	cout<<"HEY "<<i<<" "<<pt<<"   "<<x<<endl;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")