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
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

vi g[50505];
int par[50505];
int cnt[50505][505];
void add(int p,int l){
    if(p==-1)
        return;
    if(l>500)
        return;
    ++cnt[p][l];
    add(par[p],l+1);
}
int n,k;
li dfs(int v,int p = -1){
    par[v] = p;
    add(v,0);
    li ans = 0;
    for(int i=0;i<(int)g[v].size();++i){
        if(p==g[v][i])
            continue;
        ans += dfs(g[v][i], v);
    }
    ans += cnt[v][k];
    li sans = 0;
    for(int i=0;i<(int)g[v].size();++i){
        if(p==g[v][i])
            continue;
        for(int j=1;j<=k-1;++j){
            li here = cnt[g[v][i]][j-1]; //j
            li any = cnt[v][k-j] - cnt[g[v][i]][k-j-1];
            //if(v==1)
            //  cout<<"s"<<j<<' '<<here<<' '<<any<<endl;
            sans+= any*here;
        }
    }
    li res = ans + sans/2;
    //cout<<v<<' '<<ans<<' '<<sans/2<<endl;
    return res;
    
}
void solve() {
    
    cin>>n>>k;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    cout<<dfs(1,-1);
    
    
    /*for(int i=1;i<6;++i){
        cout<<endl;
        for(int j=0;j<6;++j){
            cout<<cnt[i][j]<<' ';
        }
    }*/
}