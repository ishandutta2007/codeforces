 #include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 3000000+10;
namespace ZYH{
    int n,m;
    vector<int> g[N];
    struct SCC {
        int pre[N], low[N], sccno[N], dfs_clock, scc_cnt;
        stack<int> S;
        void dfs(int u) {
            pre[u] = low[u] = ++dfs_clock;
            S.push(u);
            for (int i = 0; i < g[u].size(); i ++) {
                int v = g[u][i];
                if (! pre[v]) {
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                } else if (!sccno[v]) {
                    low[u] = min(low[u], pre[v]);
                }
            }
            if (low[u] == pre[u]) {
                scc_cnt ++;
                for (;;) {
                    int x = S.top(); S.pop();
                    sccno[x] = scc_cnt;                                                                        
                    if (x == u) break;
                }
            }
        }
        void Excalibur(int n) {
            for (int i = 1; i <= n; i ++) {
                pre[i] = low[i] = sccno[i] = 0;
            }
            while(S.size()) S.pop();
            dfs_clock = scc_cnt = 0;
            for (int i = 1 ;i <= n; i ++)
                if (pre[i] == 0) dfs(i);
        }
    } Saber;

    void add_edge(int x,int val_x,int y,int val_y) {
        //printf("%d(%d) -> %d(%d)\n", x,val_x,y,val_y);
        g[x<<1|val_x].push_back(y<<1|val_y);
    } 
}

int n,p,M,m;
struct Item {
    int l,r,id;
} it[N]; int L[N],R[N];
bool cmpl(Item a, Item b) {
    return a.l < b.l;
}
bool cmpr(Item a, Item b) {
    return a.r < b.r;
}
int main() {
    scanf("%d%d%d%d",&p,&n,&M,&m);
    for(int i=1;i<=p;i++){
        int x,y; scanf("%d%d",&x,&y);
        ZYH::add_edge(x,0,y,1);
        ZYH::add_edge(y,0,x,1);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&it[i].l,&it[i].r);
        it[i].id = i;
        L[i] = it[i].l, R[i] = it[i].r;
    }
    for(int i=1;i<=m;i++){
        int x,y; scanf("%d%d",&x,&y);
        ZYH::add_edge(x,1,y,0);
        ZYH::add_edge(y,1,x,0);
    }
    ZYH::n = 3 * n + 5;

    sort(it+1,it+1+n,cmpr);
    // var: n+1 ..... 2n
    for(int i=1;i<=n;i++) {
        if(i>1) ZYH::add_edge(n+i,1,n+i-1,1);
        if(i<n) ZYH::add_edge(n+i,0,n+i+1,0);
    }
    for(int i=1;i<=n;i++) {
        int pos=it[i].l;
        int lef,rig;
        lef=1,rig=n+1;
        while(rig-lef>1){
            int mid=(lef+rig)>>1;
            if(it[mid].r < pos) {
                lef = mid;
            } else {
                rig = mid;
            }
        }
        if(it[lef].r < pos) {
            ZYH::add_edge(it[i].id,1,n+lef,1);
        }

        ZYH::add_edge(n+i,1,it[i].id,0);
    }

    // var: 2*n+1 ..... 3*n
    sort(it+1,it+1+n,cmpl);
    for(int i=1;i<=n;i++) {
        if(i<n) ZYH::add_edge(2*n+i,1,2*n+i+1,1);
        if(i>1) ZYH::add_edge(2*n+i,0,2*n+i-1,0);
    }
    for(int i=1;i<=n;i++){
        int pos=it[i].r;
        int lef,rig;
        lef=0,rig=n;
        while(rig-lef>1) {
            int mid=(lef+rig)>>1;
            if(it[mid].l > pos) {
                rig = mid;
            } else {
                lef = mid;
            }
        }
        //`printf("i=%d, rig=%d\n", i,rig);
        if (it[rig].l > pos) {
            ZYH::add_edge(it[i].id,1,2*n+rig,1);
        }
        ZYH::add_edge(2*n+i,1,it[i].id,0);
    }
    ZYH::Saber.Excalibur(ZYH::n);
    vector<int> v;
    int mx = 0;
    for(int i=1;i<=3*n;i++) {
        if(ZYH::Saber.sccno[i<<1] == ZYH::Saber.sccno[i<<1|1] && ZYH::Saber.sccno[i<<1]  != 0)
            return !printf("-1\n");
    }
    for(int i=1;i<=n;i++) {
        //printf("%d %d,%d\n", i, ZYH::Saber.sccno[i<<1], ZYH::Saber.sccno[i<<1|1]);
        if(ZYH::Saber.sccno[i<<1] > ZYH::Saber.sccno[i<<1|1]) {
            v.push_back(i); mx = max(L[i], mx);
        }
    }
    printf("%d %d\n", v.size(), mx);
    for(auto x: v) {
        printf("%d ",x);
    }
    printf("\n");
}






/*

1 2 4 1
1 2
1 2
3 4
1 2

*/