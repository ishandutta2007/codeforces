// High above the clouds there is a rainbow...

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

vector<int>v[maxn];
set<int>st[maxn];
int bef[maxn],aft[maxn],a[maxn],ans;

void dfs(int u){
    for(int y:v[u]){
	dfs(y);
	if(sz(st[u])<sz(st[y])) swap(st[u],st[y]);
	for(int x:st[y]) ans+=st[u].count(u-x);
	for(int x:st[y]) st[u].insert(x);
	st[y].clear();
    }
    st[u].insert(u);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n;i++){
	bef[i]=i-1;
	while(bef[i]>=0 && a[bef[i]]<a[i]) bef[i]=bef[bef[i]];
    }
    for(int i=n-1;i>=0;i--){
	aft[i]=i+1;
	while(aft[i]<n && a[aft[i]]<a[i]) aft[i]=aft[aft[i]];
    }
    for(int i=0;i<n;i++){
	if(a[i]==n) continue;
	if(bef[i]==-1) v[a[aft[i]]].PB(a[i]);
	else if(aft[i]==n) v[a[bef[i]]].PB(a[i]);
	else if(a[aft[i]]<a[bef[i]]) v[a[aft[i]]].PB(a[i]);
	else v[a[bef[i]]].PB(a[i]);
    }
    dfs(n);
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.