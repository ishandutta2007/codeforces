#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = (int)1e5 + 500, K = 60;

int dat[K][MAXN * 4];
int num[MAXN];

void init_dat(int l, int r, int x){
    if(l == r){
        for(int k = 0; k < K; k++){
            dat[k][x] = (k % num[l] == 0) + 1;
        }
        return ;
    }
    int mid = (l + r) / 2;
    init_dat(l, mid, x*2+1);
    init_dat(mid+1, r, x*2+2);
    for(int k = 0; k < K; k++){
        int left = dat[k][2*x+1];
        dat[k][x] = left + dat[(left + k) % K][2*x+2];
    }
}

void update(int a, int b, int x, int l, int r, int val){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        for(int k = 0; k < K; k++){
            dat[k][x] = (k % val == 0) + 1;
        }
        return ;
    }
    update(a, b, x*2+1, l, mid, val);
    update(a, b, x*2+2, mid+1, r, val);

    for(int k = 0; k < K; k++){
        int left = dat[k][2*x+1];
        dat[k][x] = left + dat[(left + k) % K][2*x+2];
    }
}

int query(int a, int b, int x, int l, int r, int k){
    if(r < a || b < l) return 0;

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return dat[k][x];

    int LHS = query(a, b, x*2+1, l, mid, k);
    int RHS = query(a, b, x*2+2, mid+1, r, (k + LHS) % K);

    return LHS + RHS;
}

int n, q;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    init_dat(0, n-1, 0);
    scanf("%d", &q);
    while(q--){
        char c;
        int a, b;
        getchar();
        scanf("%c%d%d", &c, &a, &b);
//        cout << c << " " << a << " " << b << endl;
        if(c =='A'){
            a--, b--;
            printf("%d\n", query(a, b - 1, 0, 0, n-1, 0));
        }
        else{
            a--;
            update(a, a, 0, 0, n - 1, b);
        }
    }

}