#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int q,last;
map<int,int> par,sz,dis,tmp, vis;
int find(int x) {
    if (par[x] == x) return x;
    int p = find(par[x]);
    dis[x] = dis[par[x]] ^ tmp[x];
    return p;
}
void unite(int x,int y,int v) {
    int px=find(x);
    int py=find(y);

    if(px == py) {
        return;
    }
    if (sz[px]<sz[py]) {
        //printf("%d->%d\n", px,py);
        int dx = dis[x], dy = dis[y];
        tmp[px] ^= (v^dx^dy); sz[py] += sz[px];
        par[px] = py;
    } else {
        //printf("%d->%d\n", py,px);
        int dx = dis[x], dy = dis[y];
        tmp[py] ^= (v^dx^dy); sz[px] += sz[py];
        par[py] = px;
    }
}

int main() {
    scanf("%d",&q);
    while(q--) {
        int t,l,r,x;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1) { 
            scanf("%d",&x);
            l^=last,r^=last;x^=last;if(l>r)swap(l,r);
            //printf("$ %d %d %d %d\n", t,l,r,x);
            if(vis[l-1]==0) vis[l-1]=1, sz[l-1]=1, par[l-1]=l-1;
            if(vis[r]==0) vis[r]=1, sz[r]=1, par[r]=r;
            //printf("unite %d %d\n", l-1,r);
            unite(l-1,r,x); 
            //printf("dis = %d %d\n", dis[4],tmp[4]);
            find(l-1), find(r);
            //printf("dis = %d %d\n", dis[4],tmp[4]);
        } else {
            l^=last,r^=last; if(l>r)swap(l,r);
            //printf("# %d %d %d\n", t,l,r);
            if(vis[l-1]==0) vis[l-1]=1, sz[l-1]=1, par[l-1]=l-1;
            if(vis[r]==0) vis[r]=1, sz[r]=1, par[r]=r;

            int pl = find(l-1);
            int pr = find(r);  
            //printf("l-1=%d,pl = %d, r=%d,pr = %d\n", l-1,pl,r,pr);
            if (pl != pr) {
                printf("-1\n"); last=1;
            } else {
                printf("%d\n", dis[l-1]^dis[r]);
                last = dis[l-1]^dis[r];
            }
        }
    }
}
/*
4
1 5 5 9
2 5 5

4
1 5 5 1
1 6 6 2
1 7 7 4
2 5 6

*/