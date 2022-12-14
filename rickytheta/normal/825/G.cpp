#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int n,q;
vector<int> g[1252521];
int po[1252521];
int last = 0;
int root;
int rootval;

void dfs(int p,int bef,int mn){
    mn = min(mn, p);
    po[p] = mn;
    for(int to : g[p])if(to != bef){
        dfs(to,p,mn);
    }
}

int main(void){
    scanf("%d%d",&n,&q);
    REP(i,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    --q;
    {
        int t,x;
        scanf("%d%d",&t,&x);
        root = x;
    }
    dfs(root,-1,root);
    rootval = root;
    REP(_,q){
        int t,x;
        scanf("%d%d",&t,&x);
        int z = (x+last)%n;
        if(t==1){
            rootval = min(rootval, po[z]);
        }else{
            int ans = min(rootval, po[z]) + 1;
            printf("%d\n",ans);
            last = ans;
        }
    }
}