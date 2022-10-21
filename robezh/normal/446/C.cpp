#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int N = 300500, mod = (int)1e9 + 9;
const int K = 276601605, A[2] = {691504013, 308495997};

int n,m;
ll num[N], psum[N];
ll dat[2][4 * N];
ll lazy[2][4 * N];
ll sig[2][N], sum[2][N];

void propagate(int i, int x, int l, int r) {
    int mid = (l + r) / 2;

    ll coe = lazy[i][x];
    //dat[i][x] += coe * sum[i][r - l]; dat[i][x] %= mod;
    lazy[i][x*2+1] += coe; lazy[i][x*2+1] %= mod;
    lazy[i][x*2+2] += coe * sig[i][mid + 1 - l]; lazy[i][x*2+2] %= mod;
    dat[i][x*2+1] += coe * sum[i][mid - l]; dat[i][x*2+1] %= mod;
    dat[i][x*2+2] += coe * sig[i][mid + 1 - l] % mod * sum[i][r - (mid + 1)]; dat[i][x*2+2] %= mod;
    lazy[i][x] = 0;
}

ll query(int i, int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    //propagating the lazy value to the children
    if(lazy[i][x] > 0 && l < r) {
        propagate(i, x, l, r);
    }

    if(l >= a && r <= b) {
        return dat[i][x];
    }

    ll LHS = query(i, a, b, x*2+1, l, mid);
    ll RHS = query(i, a, b, x*2+2, mid+1, r);
    return (LHS + RHS) % mod;
}

void update(int i, int a, int b, int x, int l, int r, ll val) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;

    if(l >= a && r <= b) {
        dat[i][x] += sig[i][l - a + 1] * sum[i][r - l] % mod;
        dat[i][x] %= mod;
        lazy[i][x] += sig[i][l - a + 1];
        lazy[i][x] %= mod;
    }
    if(lazy[i][x] > 0 && l < r) {
        propagate(i, x, l, r);
    }
    if(l >= a && r <= b) return ;
    

    update(i, a, b, x*2+1, l, mid, val);
    update(i, a, b, x*2+2, mid+1, r, val);

    dat[i][x] = (dat[i][x*2+1] + dat[i][x*2+2]) % mod;
}

int main() {

    for(int i = 0; i < 2; i++){
        sum[i][0] = sig[i][0] = 1;
        for(int j = 1; j < N; j++) sig[i][j] = sig[i][j-1] * A[i] % mod;
        for(int j = 1; j < N; j++) sum[i][j] = (sum[i][j-1] + sig[i][j]) % mod;
    }
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%I64d", &num[i]);
    psum[0] = num[0];
    for(int i = 1; i < n; i++) psum[i] = (psum[i-1] + num[i]) % mod;

    for(int i = 0; i < m; i++){
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        l--, r--;
        if(x == 1){
            for(int j = 0; j < 2; j++) update(j, l, r, 0, 0, n-1, A[j]);
        }
        else{
            ll res = psum[r] - (l == 0 ? 0 : psum[l-1]);
            for(int j = 0; j < 2; j++) res += (j ? -1 : 1) * K * query(j, l, r, 0, 0, n-1);
            res = (res % mod + mod) % mod;
            printf("%d\n", (int)res);
        }
    }
}