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

using namespace std;
void solve();

#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}

int ans[3333];
vi g[3333];

bool used[3333];
bool cc[3333];
int st=0;int f;
bool dfs(int v,int p){
    //cout<<"in"<<v<<endl;
    if(used[v]){
        if(st==0){
            st=1;
            f=v;
            cc[v]=true;
        }
        return true;
    }
    bool ans=false;
    used[v]=true;
    for(int i=0;i<g[v].size();++i){
        if(g[v][i]==p)
            continue;
        ans =ans || (dfs(g[v][i],v) &&  f!=v);
    }
    if(ans)
        cc[v]=true;
    return ans;
}

int calc(int v,int p){
    if(cc[v])
        return 0;
    int ans=1<<28;
    for(int i=0;i<g[v].size();++i){
        if(g[v][i]==p)
            continue;
        ans=min(ans,calc(g[v][i],v)+1);
    }
    return ans;
}
void solve() {
    int n;
    cin>>n;
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,-1);
    for(int i=1;i<=n;++i){
        cout<<calc(i,-1)<<' ';
    }
}