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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

vector<int> v[maxn], g[maxn];
int COL, col[maxn];
bool mark[maxn];
vector<int> vec, ans1, ans2;

void dfs1(int u){
    mark[u]=1;
    for(int y:v[u])
	if(mark[y]==0) dfs1(y);
    vec.PB(u);
}
void dfs2(int u){
    mark[u]=1;
    for(int y:g[u])
	if(mark[y]==0) dfs2(y);
    col[u]=COL;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int q; cin>>q;
    while(q--){
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++){
	    v[i].clear(), g[i].clear();
	}
	for(int i=0;i<m;i++){
	    int a,b; cin>>a>>b;
	    --a,--b;
	    if(a==b) continue;
	    v[a].PB(b);
	    g[b].PB(a);
	}
	for(int i=0;i<n;i++) mark[i]=0;
	vec.clear();
	for(int i=0;i<n;i++) if(mark[i]==0) dfs1(i);
	for(int i=0;i<n;i++) mark[i]=0;
	COL=0;
	for(int i=n-1;i>=0;i--) if(mark[vec[i]]==0) dfs2(vec[i]), COL++;
	if(COL==1){
	    cout<<"No\n";
	    continue;
	}
	ans1.clear(), ans2.clear();
	for(int i=0;i<n;i++){
	    if(col[i]==COL-1) ans1.PB(i+1);
	    else ans2.PB(i+1);
	}
	cout<<"Yes\n"<<sz(ans1)<<" "<<sz(ans2)<<"\n";
	for(int x:ans1) cout<<x<<" ";
	cout<<"\n";
	for(int x:ans2) cout<<x<<" ";
	cout<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")