#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 300050;

int n,m,a,b,c,d;
bool lazy[20][MAXN];
ll dat[20][MAXN];
int num[MAXN];

ll init_sum(int i, int x, int l, int r){
    if(l == r){
        int res = num[l];
        return dat[i][x] = (res >> i) % 2;
    }
    int mid = (l + r) / 2;
    ll sum = init_sum(i, x*2+1, l, mid) + init_sum(i, x*2+2, mid+1, r);
    dat[i][x] = sum;
    return sum;
}

void propagate(int i, int x, int l, int r) {
    int mid = (l + r) / 2;

    lazy[i][x] = false;
    lazy[i][(x<<1) + 1] ^= 1;
    lazy[i][(x<<1) + 2] ^= 1;
    dat[i][(x<<1) + 1] = (mid - l + 1) - dat[i][(x<<1) + 1];
    dat[i][(x<<1) + 2] = (r - mid) - dat[i][(x<<1) + 2];
}

ll query(int i, int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    //propagating the lazy value to the children
    if(lazy[i][x] && l < r) {
        propagate(i, x, l, r);
    }

    if(l >= a && r <= b) {
        return dat[i][x];
    }

    ll lquery = query(i, a, b,  (x<<1) + 1, l, mid);
    ll rquery = query(i, a, b, (x<<1) + 2, mid+1, r);
    return lquery + rquery;
}

void update(int i, int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;



    if(l >= a && r <= b) {
        if(l != r) lazy[i][x] ^= 1;
        dat[i][x] = (r - l + 1) - dat[i][x];
        return ;
    }

    //propagating the lazy value to the children
    if(lazy[i][x] && l < r) {
        propagate(i, x, l, r);
    }

    update(i, a, b, (x<<1) + 1, l, mid);
    update(i, a, b, (x<<1) + 2, mid+1, r);

    dat[i][x] = dat[i][(x<<1) + 1] + dat[i][(x<<1) + 2];
}

void upd(int x, int l, int r){
    for(int i = 0; i < 20; i++){
        if(x%2 == 1) update(i, l, r, 0, 0, n-1);
        x /= 2;
    }
}

ll que(int l, int r){
    ll res = 0;
    for(int i = 19; i >= 0; i--){
        res *= 2;
        res += query(i, l, r, 0, 0, n-1);
    }
    return res;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    for(int i = 0; i < 20; i++) fill(lazy[i], lazy[i]+MAXN, false);
    for(int i = 0; i < 20; i++){dat[i][0] = init_sum(i, 0, 0, n-1);}

    scanf("%d", &m);
    while(m--){
        scanf("%d", &a);
        if(a == 1){
            scanf("%d%d", &b, &c);
            b--, c--;
            printf("%I64d\n", que(b,c));
        }
        else{
            scanf("%d%d%d", &b, &c, &d);
            b--, c--;
            upd(d, b, c);
        }
    }
}