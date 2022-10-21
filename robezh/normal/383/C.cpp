#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

int n,m,a,b,c;
int ival[N];
bool clr[N], vis[N];
int cont[2][2*N], ct[2];
int tcont[2*N], tct = 0, tl[N], tr[N];
int lft[N], rgt[N];
int lazy[2][4 * 2 * N];
int dat[2][4 * 2 * N];
vector<int> G[N];

void dfs(int v, bool bk){
    vis[v] = true;
    clr[v] = bk;
    lft[v] = ct[bk];
    cont[bk][ct[bk]++] = v;

    tl[v] = tct;
    tcont[tct++] = v;
    for(int nxt : G[v]){
        if(!vis[nxt]) dfs(nxt, !bk);
    }
    rgt[v] = ct[bk];
    cont[bk][ct[bk]++] = v;
    tr[v] = tct;
    tcont[tct++] = v;
}

void propagate(int i, int x, int l, int r) {
    int mid = (l + r) / 2;

    lazy[i][x*2+1] += lazy[i][x];
    lazy[i][x*2+2] += lazy[i][x];
    dat[i][(x<<1) + 1] += (mid - l + 1) * lazy[i][x];
    dat[i][(x<<1) + 2] += (r - mid) * lazy[i][x];
    lazy[i][x] = 0;
}

int query(int i, int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    //propagating the lazy value to the children
    if(lazy[i][x] != 0 && l < r) {
        propagate(i, x, l, r);
    }

    if(l >= a && r <= b) {
        return dat[i][x];
    }

    int lquery = query(i, a, b,  (x<<1) + 1, l, mid);
    int rquery = query(i, a, b, (x<<1) + 2, mid+1, r);
    return lquery + rquery;
}

int query(int i, int t){
    //cout << "querying i, from, to : " << i << ", " << lft[t] << ", " << lft[t] << ", up to " << ct[i]-1 << endl;
    int res = query(i, lft[t], lft[t], 0, 0, ct[i]-1);
    return res;

}

void update(int i, int a, int b, int x, int l, int r, int val) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;

    //propagating the lazy value to the children
    if(lazy[i][x] != 0 && l < r) {
        propagate(i, x, l, r);
    }

    if(l >= a && r <= b) {
        if(l != r) lazy[i][x] = val;
        dat[i][x] += (r - l + 1) * val;
        return ;
    }

    update(i, a, b, (x<<1) + 1, l, mid, val);
    update(i, a, b, (x<<1) + 2, mid+1, r, val);

    dat[i][x] = dat[i][(x<<1) + 1] + dat[i][(x<<1) + 2];
}

void update(int i, int a, int b, int val){
    //cout << "updating i, a, b, val: " << i << ", " << a << ", " << b << ", " << val << endl;
    update(i, a, b, 0, 0, ct[i]-1, val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> ival[i];
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, true);


    while(m--){
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            b--;
            update(clr[b], lft[b], rgt[b], c);
            if(tl[b]+1 != tr[b]) update(!clr[b], lft[tcont[tl[b]+1]], rgt[tcont[tr[b]-1]], -c);
        }
        else{
            cin >> b;
            b--;
            cout << query(clr[b], b) + ival[b] << endl;
        }
    }
}