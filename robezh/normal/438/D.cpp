#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;
typedef long long ll;

int n,m;
int num[N];
ll dat[4*N], mx[4*N];

void init_dat(int l, int r, int x){
    if(l == r){dat[x] = mx[x] = num[l]; return ;}

    int mid = (l + r) / 2;
    init_dat(l, mid, x*2+1);
    init_dat(mid+1, r, x*2+2);
    dat[x] = dat[2*x+1] + dat[2*x+2];
    mx[x] = max(mx[2*x+1], mx[2*x+2]);
}

void update(int a, int b, int x, int l, int r, int val){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        dat[x] = mx[x] = val;
        return ;
    }
    update(a, b, x*2+1, l, mid, val);
    update(a, b, x*2+2, mid+1, r, val);

    dat[x] = dat[2*x+1] + dat[2*x+2];
    mx[x] = max(mx[2*x+1], mx[2*x+2]);
}

ll get_sum(int a, int b, int x, int l, int r){
    if(r < a || b < l) return 0;

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return dat[x];

    ll LHS = get_sum(a, b, x * 2 + 1, l, mid);
    ll RHS = get_sum(a, b, x * 2 + 2, mid + 1, r);

    return LHS + RHS;
}

ll get_mx(int a, int b, int x, int l, int r){
    if(r < a || b < l) return 0;

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return mx[x];

    ll LHS = get_mx(a, b, x * 2 + 1, l, mid);
    ll RHS = get_mx(a, b, x * 2 + 2, mid + 1, r);

    return max(LHS, RHS);
}



void remd(int a, int b, int x, int l, int r, int mod){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;

    if(l == r){
        dat[x] %= mod;
        mx[x] %= mod;
        return ;
    }

    if(get_mx(a, b, x *  2 + 1, l, mid) >= mod) remd(a, b, x*2+1, l, mid, mod);
    else remd(a, b, x*2+2, mid+1, r, mod);

    dat[x] = dat[x*2+1] + dat[x*2+2];
    mx[x] = max(mx[x*2+1], mx[x*2+2]);
}



int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    init_dat(0, n-1, 0);
    for(int i = 0; i < m; i++){
        int a;
        scanf("%d", &a);
        if(a == 1){
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%I64d\n", get_sum(l - 1, r - 1, 0, 0, n - 1));
        }
        else if(a == 2){
            int l, r, mod;
            scanf("%d%d%d", &l, &r, &mod);
            while(get_mx(l - 1, r - 1, 0, 0, n - 1) >= mod){
                remd(l-1, r-1, 0, 0, n-1, mod);
            }

        }
        else{
            int k, x;
            scanf("%d%d", &k, &x);
            update(k-1, k-1, 0, 0, n-1, x);
        }
    }
}