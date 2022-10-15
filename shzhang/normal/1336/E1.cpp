#include <cstdio>

using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define bwt(a) __builtin_popcountll((unsigned ll)(a))

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int n, m;
ll basis[60]; int basis_size = 0;

ll cnt[2050][50];
bool low[2050];
ll ans[60];

void search(int bit, ll cur)
{
    if (bit == 10) {
        cnt[cur & ((1LL << 11LL) - 1LL)][bwt(cur & (~((1LL << 11LL) - 1LL)))]++; return;
    }
    search(bit-1, cur);
    if (basis[bit]) search(bit-1, cur ^ basis[bit]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        ll val; scanf("%lld", &val);
        for (ll j = 34; j >= 0; j--) {
            if (!(val & (1LL << j))) continue;
            if (!basis[j]) {
                basis[j] = val; basis_size++; break;
            } else {
                val ^= basis[j];
            }
        }
    }
    //fprintf(stderr, "HERE\n");
    search(34, 0);
    for (int i = 0; i < (1 << 11); i++) {
        ll curv = 0; bool good = true;
        for (int j = 0; j < 11; j++) {
            if (i & (1 << j)) {
                if (!basis[j]) {
                    good = false; break;
                } else {
                    curv ^= basis[j];
                }
            }
        }
        if (!good) continue;
        low[curv] = true;
    }
    for (int i = 0; i < (1 << 11); i++) {
        if (!low[i]) continue;
        for (int j = 0; j < (1 << 11); j++) {
            for (int k = 0; k <= 24; k++) {
                ans[k + bwt(i^j)] += cnt[j][k];
            }
        }
    }
    for (int i = 0; i <= m; i++) ans[i] %= MOD;
    for (int i = 0; i <= m; i++) ans[i] = mul(ans[i], fpow(2, n - basis_size));
    for (int i = 0; i <= m; i++) printf("%lld ", ans[i]);
    return 0;
}