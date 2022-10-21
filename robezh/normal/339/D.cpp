#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = (1 << 17) + 500;

int n,m,t,a,b;
int dat[MAXN * 4];
int num[MAXN];

void init_dat(int l, int r, int x, int k){
    if(l == r){
        dat[x] = num[l];
        return ;
    }
    int mid = (l + r) / 2;
    init_dat(l, mid, x*2+1, 1-k);
    init_dat(mid+1, r, x*2+2, 1-k);
    if(k) dat[x] = dat[2*x+1] | dat[2*x+2];
    else dat[x] = dat[2*x+1] ^ dat[2*x+2];
}

void update(int a, int b, int x, int l, int r, int val, int k){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        dat[x] = val;
        return ;
    }
    update(a, b, x*2+1, l, mid, val, 1-k);
    update(a, b, x*2+2, mid+1, r, val, 1-k);

    if(k) dat[x] = dat[2*x+1] | dat[2*x+2];
    else dat[x] = dat[2*x+1] ^ dat[2*x+2];
}

int main(){
    scanf("%d%d", &t, &m);
    n = (1 << t);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    init_dat(0, n-1, 0, t%2);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--;
        update(a,a,0,0,n-1,b,t%2);
        printf("%d\n", dat[0]);
    }
}