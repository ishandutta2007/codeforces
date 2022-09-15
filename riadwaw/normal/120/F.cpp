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
#include <stack>
using namespace std;
void solve();
typedef pair<int,int> pi;
typedef long long li;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
int main(){
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
vi g[1000];
int level[1000];
int curmax=0;
void dfs(int v,int p,int lev){
    level[v]=lev;
    if(p==-1 || level[curmax]<lev)
        curmax=v;
    for(int i=0;i<g[v].size();++i){
        if(p!=g[v][i])
            dfs(g[v][i],v,lev+1);
    }
}
void solve(){
    int n;
    cin>>n;
    int s=0;
    for(int i=0;i<n;++i){
        int m;
        scanf("%d",&m);
        for(int j=1;j<=m;++j){
            g[j].clear();
        }
        int a,b;
        for(int i=1;i<m;++i){
            scanf("%d %d",&a,&b);
            g[a].pb(b);
            g[b].pb(a);

        }

        dfs(1,-1,0);
        dfs(curmax,-1,0);
        
        s+=level[curmax];
    }

    cout<<s;

}