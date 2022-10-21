#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 500;

int n,q,x,y;
bool dat[8 * N];
bool lazy[8 * N], vis[N];
vector<int> num;
vector<int> G[N];
int par[N];
int st[N], ed[N];

void dfs(int i){
    vis[i] = 1;
    num.push_back(i);
    st[i] = num.size() - 1;
    for(int nxt : G[i]){
        if(!vis[nxt]){
            par[nxt] = i;
            dfs(nxt);
        }
    }
    num.push_back(i);
    ed[i] = num.size() - 1;
}

void propagate(int x) {
    lazy[x] = 0;
    lazy[(x<<1) + 1] = 1;
    lazy[(x<<1) + 2] = 1;
    dat[(x<<1) + 1] = 0;
    dat[(x<<1) + 2] = 0;
}

bool query(int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    //propagating the lazy value to the children
    if(lazy[x] && l < r) {
        propagate(x);
    }

    if(l >= a && r <= b) {
        return dat[x];
    }

    bool lquery = query(a, b,  (x<<1) + 1, l, mid);
    bool rquery = query(a, b, (x<<1) + 2, mid+1, r);
    return lquery | rquery;
}

void updateclear(int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;

    //propagating the lazy value to the children
    if(lazy[x] && l < r) {
        propagate(x);
    }

    if(a <= l && r <= b) {
        if(l != r) lazy[x] = 1;
        dat[x] = 0;
        return ;
    }

    updateclear(a, b, (x<<1) + 1, l, mid);
    updateclear(a, b, (x<<1) + 2, mid+1, r);

    dat[x] = dat[(x<<1) + 1] | dat[(x<<1) + 2];
}

void updatefill(int a, int x, int l, int r){
    int mid = (l + r) / 2;
    if(r < a || l > a) return ;

    //propagating the lazy value to the children
    if(lazy[x] && l < r) {
        propagate(x);
    }

    if(l == r && a == r) {
        dat[x] = 1;
        return ;
    }

    updatefill(a, (x<<1) + 1, l, mid);
    updatefill(a, (x<<1) + 2, mid+1, r);

    dat[x] = dat[(x<<1) + 1] | dat[(x<<1) + 2];
}

int main(){
    fill(vis, vis+N, 0);
    fill(lazy, lazy+8*N, 0);
    fill(dat, dat+8*N, 1);
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &x, &y);
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    par[0] = -1;
    dfs(0);
    //cout << num.size() << endl;
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &x, &y); y--;
        if(x == 1){
            bool que = query(st[y], ed[y], 0, 0, (2*n-1));
            if(que){
                updateclear(st[y], ed[y], 0, 0, (2*n-1));
                if(par[y] != -1) updatefill(st[par[y]],0,0, (2*n-1));
            }
        }else if(x == 2){
            updatefill(st[y], 0, 0, (2*n-1));
        }else{
            if(!query(st[y], ed[y], 0, 0, (2*n-1))) printf("1\n");
            else printf("0\n");
        }
    }

}