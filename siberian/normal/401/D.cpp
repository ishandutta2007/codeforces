#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXBIT = 18, MAXM = 101;

ll n;
int m;

void read() {
    cin >> n >> m;
}

ll dp[1 << MAXBIT][MAXM];

int cnt[10];
int pref[10];
int pows[MAXM];
ll ans;

void run() {
    pows[0] = 1;
    for (int i = 1; i < MAXM; i++) {
        pows[i] = 10 * pows[i - 1] % m;
    }

    int full = 0;
    while (n) {
        cnt[n % 10]++;
        n /= 10;
        full++;
    }
    for (int i = 0; i < 10; i++) {
        pref[i] = pref[i - 1] + cnt[i - 1];
    }

    dp[0][0] = 1;
    for (int mask = 0; mask < (1 << full) - 1; mask++) {
        int cnt_bits = __builtin_popcount(mask);
        for (int x = 0; x < 10; x++) {
            if (cnt[x] == 0) continue;
            int nxt_mask = mask;
            for (int bit = pref[x]; bit < pref[x] + cnt[x]; bit++) {
                if ((mask >> bit) & 1) continue;
                nxt_mask |= (1 << bit);
                break;
            }
            if (nxt_mask == mask) continue;
            if (x == 0 && nxt_mask == (1 << full) - 1) continue;

            int add_mod = pows[cnt_bits] * x % m;

            for (int mod = 0; mod < m; mod++) {
                if (dp[mask][mod] == 0) continue;
                dp[nxt_mask][(mod + add_mod) % m] += dp[mask][mod];
            }
        }
    }

    ans = dp[(1 << full) - 1][0];
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}