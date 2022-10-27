#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

const LL NICO = 400000 + 10;

LL n;
LL a[NICO], g[NICO]; bool is_max[NICO];
int cnt[NICO];

LL ans = 0;

LL gcd(LL x, LL y) {
    return y == 0 ? x: gcd(y, x % y);
}

void init() {
    for(int i = 1; i <= n; i ++) {
        cnt[g[i] = gcd(i, n)] ++;
    }
}

LL cac(LL len, LL x) {
    //printf("cac: %lld %lld ", len, x);
    if(x == n) return 0;
    LL res = 0;
    for(int i = 1; i <= len; i ++) {
        if(g[i] == x) {
            res += len - i + 1;
        }
    }
    //printf("%lld\n", res);
    return res;
}

LL cac_cir(LL len, LL x) {
    //printf("cac_cir: %lld %lld\n", len, x);
    if(x == n) return 0;
    LL res = len * cnt[x];
    return res;
}

void solve(int x) {
    //cout << x << endl;
    
    for(int i = 1; i <= 2*n; i ++) is_max[i] = 0;

    for(int i = 1; i <= x; i ++) {
        int mx = -1, mx_pos = i;
        for(int j = i; j <= n; j += x) {
            if(a[j] > mx) mx = a[j], mx_pos = j; 
        }
        for(int j = i; j <= n; j += x) {
            if(a[j] == mx) is_max[j] = 1;
        }
        //printf("x = %d mx_pos = %d\n", x, mx_pos);
    }

    int last;
    for(last = 1; last <= n && is_max[last] == 1; last ++){}

    if(last == n + 1) {
        ans += cac_cir(n, x); return;
    }

    //printf("last: %d\n", last);
    int cnt = 0;
    for(int i = 1; i < last; i ++) is_max[n + i] = is_max[i];
    for(int i = last; i < n + last; i ++) {
        if(is_max[i]) {
            cnt ++;
        } else {
            if(cnt) ans += cac(cnt, x);
            cnt = 0;
        }
    }
    if(cnt) ans += cac(cnt, x);

}

int main() {
    scanf("%lld", &n);
    init();
    for(int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
    }

    for(int t = 1; t * t <= n; t ++) {
        if(n % t == 0) {
            solve(t); if(t * t != n) solve(n / t);
        }
    }

    printf("%lld\n", ans);
}