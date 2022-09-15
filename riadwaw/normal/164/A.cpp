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
    //freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
int d[101010];

vector<int> g[101010];
vector<int> obr[101010];

bool used1[101010];
bool used2[101010];


void dfs1(int v){
    //cout<<"dfs1"<<v<<endl;
    if(used1[v])
        return;
    used1[v] = true;
    for(int i=0;i<g[v].size();++i){
        if(d[g[v][i]]!=1)
            dfs1(g[v][i]);
    }
}
void dfs2(int v){
    //cout<<"dfs2"<<v<<endl;
    if(used2[v])
        return;
    used2[v] = true;
    if(d[v] == 1)
        return;
    //cout<<"size"<<obr[v].size()<<endl;
    for(int i=0;i<obr[v].size();++i){
        dfs2(obr[v][i]);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>d[i];
    }
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].pb(b);
        obr[b].pb(a);
    }
    for(int i=0;i<n;++i){
        if(d[i] == 1){
            dfs1(i);
        }
    }
    
    for(int i=0;i<n;++i){
        if(d[i] == 2)
            dfs2(i);
    }
    
    for(int i=0;i<n;++i){
        cout<<(used1[i] && used2[i])<<endl;
    }
    
    
    
}