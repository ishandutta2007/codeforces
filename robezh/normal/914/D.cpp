#include <bits/stdc++.h>
using namespace std;

#define MAXN 500050

int dat[MAXN * 4];
int num[MAXN];
int n,m;
int a,l,r,x;
int lk, rk, xk;

int gcd(int x, int y){
    return x == 0 ? y : gcd(y % x, x);
}

void init_dat(int x, int l, int r){
    int mid= (l + r) / 2;

    if(l == r){
        dat[x] = num[l];
        return;
    }

    init_dat(x*2+1, l, mid);
    init_dat(x*2+2, mid+1, r);

    dat[x] = gcd(dat[x*2+1], dat[x*2+2]);
}

int query(int a, int b, int x, int l, int r, int d){
    if(r < a || l > b) return 0;

    if(a <= l && r <= b){
        if(dat[x] % d != 0){
            lk = l;
            rk = r;
            xk = x;
            return 1;
        }
        return 0;
    }

    int mid = (l + r) / 2;

    int left = query(a,b,x*2+1,l,mid,d);
    int right = query(a,b,x*2+2,mid+1,r,d);

    return left + right;
}

bool check_query(int l, int r, int x, int d){
    if(l == r) return (dat[x] % d != 0) ;
    int mid = (l + r) / 2;
    bool LHS = (dat[x*2+1] % d != 0);
    bool RHS = (dat[x*2+2] % d != 0);
    if(LHS == RHS) return false;
    else return LHS ? check_query(l, mid, x*2+1, d) : check_query(mid+1, r, x*2+2, d);
}

void update(int k, int x, int l, int r, int t){
    if(r < k || l > k) return ;

    if(l == r && l == k){
        dat[x] = t;
        return ;
    }

    int mid = (l + r) / 2;
    update(k, x*2+1, l, mid, t);
    update(k, x*2+2, mid+1, r, t);

    dat[x] = gcd(dat[x*2+1], dat[x*2+2]);
}



int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    init_dat(0,0,n-1);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &a);
        if(a == 1){
            bool good;
            scanf("%d%d%d",&l,&r,&x);
            l--, r--;
            int q = query(l,r,0,0,n-1,x);
            if(q > 1){printf("NO\n"); continue;}
            if(q == 0){printf("YES\n"); continue;}
            printf(check_query(lk,rk,xk,x) ? "YES\n" : "NO\n");
        } else{
            scanf("%d%d", &l, &x); l--;
            update(l,0,0,n-1,x);
        }
    }
}