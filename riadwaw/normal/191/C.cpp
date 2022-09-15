#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

int ans[101010];

vector<pi> g[101010];
int cnt[101010];
int cntlca[101010];
int dfs(int v,int p=-1,int edgeID = -1){
    li fromC = 0;
    for(pi to: g[v]){
        if(to.first != p)
            fromC+=dfs(to.first, v, to.second);
    }
    if(p!=-1){
        return ans[edgeID] = cnt[v] + fromC - cntlca[v] * 2;
    }
    return 0;
}


int n, l;
int tin[101010], tout[101010];
int timer;
vector<int> up[101010];

void dfs2 (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        if (to != p)
            dfs2 (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}


void solve(){
    cin>>n;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].pb(mp(b, i));
        g[b].pb(mp(a, i));
    }
    int k;
    cin>>k;
    
    
    
    
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs2 (0);
    
    for(int i=0;i<k;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        cnt[a]++;
        cnt[b]++;
        cntlca[lca(a,b)]++;
    }
    
    
    dfs(0);
    
    for(int i=0;i<n-1;++i){
        cout<<ans[i]<<' ';
    }
    
    
}