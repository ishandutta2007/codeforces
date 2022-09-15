#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
int n;
int p[5200];
int m[5200][5200];
vi g[5200];
int parent[5200];
vi por;
priority_queue<pi> s[5200];
void dfs(int v){
    for(int i=0;i<g[v].size();++i){
        if(parent[v]==g[v][i])
            continue;
        parent[g[v][i]]=v;
        por.pb(g[v][i]);
        dfs(g[v][i]);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<n;++i){
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        g[a].pb(b);
        g[b].pb(a);
        m[a][b]=m[b][a]=t;
    }
    cout<<0<<' ';
    for(int i=2;i<=n;++i){
        s[i].push(pi(-p[i],i));
    }
    dfs(1);
    int ans[5200];
    for(int k=1;k<=5010;++k){
        for(int i=0;i<por.size();++i){
            int c=m[por[i]][parent[por[i]]];
            while(c-- && s[por[i]].size()){
                pi cur= s[por[i]].top();
                if(parent[por[i]]==1)
                    ans[cur.second]=k;
                else{
                    s[parent[por[i]]].push(cur);
                }
                s[por[i]].pop();
            }
        }
    }
    for(int i=2;i<=n;++i){
        printf("%d ",ans[i]);
    }
}