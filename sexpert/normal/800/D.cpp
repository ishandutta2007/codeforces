#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
ll cnt[MAXN], sum[MAXN], ssq[MAXN], dp[MAXN], p2[MAXN], G[MAXN];
int n;
const vector<int> pt = {1, 10, 100, 1000, 10000, 100000};

int get(int x, int d) {
    return (x / pt[d]) % 10;
}

void add(ll &x, ll y) {
    x += y;
    if(x < 0)
        x += MOD;
    if(x >= MOD)
        x -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p2[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p2[i] = (p2[i - 1] + p2[i - 1]) % MOD;

    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        add(cnt[x], 1);
        add(sum[x], x);
        add(ssq[x], (x*x) % MOD);
    }

    for(int d = 0; d < 6; d++) {
        for(int ms = 999999; ms >= 0; ms--) {
            int dg = get(ms, d);
            if(dg != 9) {
                add(cnt[ms], cnt[ms + pt[d]]);
                add(sum[ms], sum[ms + pt[d]]);
                add(ssq[ms], ssq[ms + pt[d]]);
            }
        }
    }

    for(int x = 0; x < 1000000; x++) {
        if(cnt[x] == 0)
            dp[x] = 0;
        else if(cnt[x] == 1)
            dp[x] = ssq[x];
        else
            dp[x] = (((sum[x] * sum [x]) % MOD + ssq[x]) * p2[cnt[x] - 2]) % MOD;
        //cout << x << " " << dp[x] << '\n';
    }
    //cout << flush;

    ll res = 0;
    for(int x = 0; x < 1000000; x++) {
        for(int ms = 0; ms < (1 << 6); ms++) {
            bool good = true;
            int trans = x;
            for(int d = 0; d < 6; d++) {
                if(!(ms & (1 << d)))
                    continue;
                int dig = get(x, d);
                if(dig == 9) {
                    good = false;
                    break;
                }
                trans += pt[d];
            }
            if(good)
                add(G[x], dp[trans] * ((__builtin_popcount(ms) % 2) ? -1 : 1));
        }
        //if(G[x] > 0)
        //    cout << x << " " << G[x] << '\n';
        G[x] = x * G[x];
        res ^= G[x];
    }
    cout << res << '\n';
}