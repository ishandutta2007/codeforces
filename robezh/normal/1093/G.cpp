#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500, K = 32;

struct node{
    int idx[32];
    node(){};
    node(int i){fill(idx, idx+32, -1);}
    node(int a[]){
        for(int i = 0; i < 32; i++) idx[i] = a[i];
    }
};

int num[N][5];
int pt[5];
int val[N][32];
node dat[N * 4];

int get_val(int i, int mask){
    int res = 0;
    for(int j = 0; j < 5; j++){
        res += (mask & 1 ? num[i][j] : -num[i][j]);
        mask /= 2;
    }
    return res;
}

void setpoint(int x, int l){
    for(int mask = 0; mask < K; mask++){
        dat[x].idx[mask] = l;
        val[l][mask] = get_val(l, mask);
    }
}

void max_node(node &to, node &a, node &b){
    if(a.idx[0] == -1){
        to = b; return ;
    }
    if(b.idx[0] == -1){
        to = a; return ;
    }
    for(int mask = 0; mask < K; mask++){
        to.idx[mask] = (val[a.idx[mask]][mask] > val[b.idx[mask]][mask] ? a.idx[mask] : b.idx[mask]);
    }
}

node get_max_node(node &a, node &b){
    node res;
    max_node(res, a, b);
    return res;
}

void init_dat(int l, int r, int x){
    if(l == r){
        setpoint(x, l);
        return ;
    }

    int mid = (l + r) / 2;
    init_dat(l, mid, x*2+1);
    init_dat(mid+1, r, x*2+2);
    max_node(dat[x], dat[2*x+1], dat[2*x+2]);
}

void update(int a, int b, int x, int l, int r){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        setpoint(x, l);
        return ;
    }
    update(a, b, x*2+1, l, mid);
    update(a, b, x*2+2, mid+1, r);

    max_node(dat[x], dat[2*x+1], dat[2*x+2]);
}

node query(int a, int b, int x, int l, int r){
    if(r < a || b < l) return node(0);

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return dat[x];

    node LHS = query(a, b, x*2+1, l, mid);
    node RHS = query(a, b, x*2+2, mid+1, r);

    return get_max_node(LHS, RHS);
}

int get_dis(int i, int j){
    int res = 0;
    for(int k = 0; k < 5; k++){
        res += abs(num[i][k] - num[j][k]);
    }
    return res;
}

int n, k, q;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++) scanf("%d", &num[i][j]);
    }
    init_dat(0, n-1, 0);
    scanf("%d", &q);
    while(q--){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int id; scanf("%d", &id);
            id--;
            for(int i = 0; i < k; i++) scanf("%d", &pt[i]);
            for(int i = 0; i < 5; i++) num[id][i] = pt[i];
            update(id, id, 0, 0, n - 1);
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            node qry = query(l, r, 0, 0, n-1);
            int res = 0;
            for(int i = 0; i < 16; i++) res = max(res, get_dis(qry.idx[i], qry.idx[31-i]));
            printf("%d\n", res);
        }
    }
}