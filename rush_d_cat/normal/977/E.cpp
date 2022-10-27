#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)

const int N=200000+10;
const double EPS = 1e-8;
int n,m,ok;
bool vis[N]; int deg[N];
vector<int> g[N];

void dfs(int x) {
    if (deg[x] != 2) ok = 0;
    if (vis[x]) return;
    vis[x]=1;
    //printf("%d\n", x);
    for(int i=0;i<g[x].size();i++) {
        int y=g[x][i];
        dfs(y);
    }
}

int main(){
    rd(n), rd(m);
    rep(i,1,m) {
        int u,v;rd(u),rd(v);
        g[u].pb(v); deg[u] ++;
        g[v].pb(u); deg[v] ++;
    }
    int ans=0;
    rep(i,1,n){
        if(vis[i]) continue;
        ok = 1;
        dfs(i);
        if(ok) ans++;
    }
    cout<<ans<<endl;
}