#include <iostream>
#include <set>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
const LL MOD = 998244353;

int n, q;
LL p[N], pre[N], presum[N], inv[N];

LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x >> 1);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD;
}

LL cac(int l, int r) {
    LL win = pre[r] * mpow(pre[l-1], MOD - 2) % MOD;
    LL Round = (mpow(win, MOD - 2) - 1 + MOD) % MOD;
    LL E = (presum[r - 1] - (l >= 2 ? presum[l-2] : 0)) * inv[l-1] % MOD;
    E = E - win * (r- l + 1) % MOD; 
    E = E * mpow( (1 - win + MOD) % MOD, MOD - 2 ) % MOD;
    E = (E % MOD + MOD) % MOD;
    return (E * Round + (r - l + 1)) % MOD;
}
LL INV[102];
int main() {
    LL PW = mpow(100, MOD - 2);
    for (int i = 1; i <= 100; i ++) {
        INV[i] = mpow(PW * i % MOD, MOD - 2);
    }
    scanf("%d%d", &n, &q);
    
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &p[i]);
    }
    pre[0] = 1; inv[0] = 1;
    for (int i = 1; i <= n; i ++) {
        inv[i] = inv[i - 1] * INV[p[i]] % MOD; 
        p[i] = p[i] * PW % MOD;
        pre[i] = pre[i - 1] * p[i] % MOD;   
    }
    presum[0] = 1; 
    for (int i = 1; i <= n; i ++) {
        presum[i] = (presum[i-1] + pre[i]) % MOD;
    }

    set<int> st;
    st.insert(1); st.insert(n + 1);
    LL ans = cac(1, n);
    for (int i = 1; i <= q; i ++) {
        int x; scanf("%d", &x);
        if (st.count(x)) {
            auto it = st.find(x);
            -- it; int lef = * it;
            ++ it; ++ it; int rig = * it;
            ans = ans + cac(lef, rig - 1);
            ans = ans - cac(lef, x - 1) - cac(x, rig - 1);
            st.erase(x);
            ans = (ans % MOD + MOD) % MOD;
        } else {
            st.insert(x);
            auto it = st.find(x);
            -- it; int lef = * it;
            ++ it; ++ it; int rig = * it;
            ans = ans - cac(lef, rig - 1);
            ans = ans + cac(lef, x - 1) + cac(x, rig - 1);
            ans = (ans % MOD + MOD) % MOD;
        }
        printf("%lld\n", ans);
    }
    //printf("%lld\n", (cac(1, 1) + cac(2, 5)) % MOD );
}