//40_E
#include <bits/stdc++.h>
using namespace std;

#define N 1011

int modpow(int a, int b, int mod){
    if(!b) return 1;
    int r = modpow(a, b / 2, mod);
    r = 1ll * r * r % mod;
    if(b & 1) return 1ll * r * a % mod;
    return r;
}

int calc(int n, int m, int r[], int c[], int cd[], int mod){
    int ans = 1, ok = 0;
    for(int i = 1; i <= m; i ++) {
        if(!c[i]) {
            if(cd[i] != -1) return 0;
        }
        else if(c[i] < n) ans = 1ll * ans * modpow(2, c[i] - 1, mod) % mod;
        else {
            if(ok) ans = 1ll * ans * modpow(2, n - 1, mod) % mod;
            else ok = 1;
        }
    }
    return ans;
}

int n, m, k, p;
int r[N], c[N];
int rd[N], cd[N];

int main(){
    //freopen("e.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i ++) r[i] = m, rd[i] = 1;
    for(int i = 1; i <= m; i ++) c[i] = n, cd[i] = 1;
    for(int i = 0; i < k; i ++){
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        r[a] --, c[b] --;
        rd[a] *= d, cd[b] *= d;
    }
    scanf("%I64d", &p);

    if((n - m) % 2 != 0) {puts("0"); return 0;}
    if(n < m) printf("%d\n", calc(n, m, r, c, cd, p));
    else printf("%d\n", calc(m, n, c, r, rd, p));
    ///return 9;
}