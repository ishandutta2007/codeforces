#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

int par[100005];
int r[100005];
void init(){for(int i=0;i<=100000;++i)par[i]=i;}
int getpar(int u){return (par[u]==u?u:(par[u]=getpar(par[u])));}
void join(int u, int v){
    int x = getpar(u);
    int y = getpar(v);
    if(x == y) return;
    if(r[x] != r[y]){
        if(r[x] > r[y])par[y] = x;
        else par[x] = y;
    } else {
        r[x]++;
        par[y] = x;
    }
}
int N, M, Q;
int u,v,c;
map<int,int> color[100005];
map<pair<int,int>,int> ans;
typedef map<int,int>::iterator mit;
int main(){
    scanf("%d%d",&N,&M);
    init();
    for(int i=1;i<=M;++i){
        scanf("%d%d%d",&u,&v,&c);
        int a = 0, b = 0;
        if(color[u].count(c)) a = color[u][c];
        if(color[v].count(c)) b = color[v][c];
        color[u][c] = i;
        color[v][c] = i;
        if(a>0) join(i,a);
        if(b>0) join(i,b);
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        if(ans.count(make_pair(u,v))){
            printf("%d\n",ans[make_pair(u,v)]);
            continue;
        }
        int ret = 0;
        if(color[u].size() > color[v].size())swap(u,v);
        for(mit uit = color[u].begin(); uit != color[u].end(); ++uit){
            mit vit = color[v].find(uit->first);
            if(vit == color[v].end()) continue;
            if(getpar(uit->second) == getpar(vit->second)) ++ret;
        }
        if(u>v)swap(u,v);
        ans[make_pair(u,v)] = ret;
        printf("%d\n", ret);
    }
    return 0;
}