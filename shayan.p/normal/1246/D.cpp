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
 
vector<int> v[maxn], vec, ans;
int h[maxn], pr[maxn], pp[maxn];
int far[maxn];

void dfs(int u){
    pp[u]= sz(vec) ? vec.back() : 0;
    vec.PB(u);
    sort(v[u].begin(), v[u].end(), [](int a,int b){ return far[a] < far[b]; });

    for(int y:v[u])
	dfs(y);
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
 
    int n; cin>>n;
 
    for(int i=1;i<n;i++){
	cin>>pr[i];
	v[ pr[i] ].PB(i);
	h[i]= h[ pr[i] ]+1;
    }
    for(int i=n-1;i>=0;i--){
	far[i]= h[i];
	for(int j:v[i])
	    far[i]= max(far[i], far[j]);
    }

    dfs(0);
    for(int u:vec)
	while(pp[u]!=pr[u])
	    pp[u]=pp[pp[u]], ans.PB(u);
    for(int i=0;i<n;i++)
	cout<<vec[i]<<" ";
    cout<<"\n";
    cout<<sz(ans)<<"\n";
    for(int x:ans)
	cout<<x<<" ";
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.
 
 
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")