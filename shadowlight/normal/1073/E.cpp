#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 998244353;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

void add(ll &x, ll y) {
    x = (x + y) % INF;
    if (x < 0) x += INF;
}

vector <ll> st;

void init() {
    st.push_back(1);
    for (ll i = 1; i < 50; i++) {
        st.push_back(st.back() * 10LL % INF);
    }
}

ll calc1(ll len, ll k) {
    ll M = (1LL << 10);
    ll dp[len + 1][M];
    ll sums[len + 1][M];
    for (ll i = 0; i <= len; i++) {
        for (ll j = 0; j < M; j++) {
            dp[i][j] = 0;
            sums[i][j] = 0;
        }
    }
    for (ll i = 1; i <= 9; i++) {
        dp[1][1 << i] = 1;
        sums[1][1 << i] = st[len - 1] * i % INF;
    }
    for (ll len1 = 2; len1 <= len; len1++) {
        for (ll mask = 0; mask < M; mask++) {
            for (ll i = 0; i < 10; i++) {
                ll mask1 = mask | (1 << i);
                add(dp[len1][mask1], dp[len1 - 1][mask]);
                add(sums[len1][mask1], dp[len1 - 1][mask] * i % INF * st[len - len1] % INF);
                add(sums[len1][mask1], sums[len1 - 1][mask]);
            }
        }
    }
    ll res = 0;
    for (ll i = 0; i < M; i++) {
        ll d = __builtin_popcount(i);
        if (d <= k) {
            add(res, sums[len][i]);
        }
    }
    return res;

}

ll calc(ll r, ll k) {
    if (!r) return 0;
    ll res = 0;
    ll M = (1 << 10);
    ll cnt = 0;
    ll rt = r;
    vector <ll> num;
    while (rt) {
        cnt++;
        num.push_back(rt % 10);
        rt /= 10;
    }
    reverse(num.begin(), num.end());
    for (ll i = 1; i < cnt; i++) {
        add(res, calc1(i, k));
    }
    ll dp[cnt + 1][M][2];
    ll sums[cnt + 1][M][2];
    for (ll len = 0; len <= cnt; len++) {
        for (ll j = 0; j < M; j++) {
            for (ll p = 0; p < 2; p++) {
                dp[len][j][p] = 0;
                sums[len][j][p] = 0;
            }
        }
    }
    for (ll i = 1; i < num[0]; i++) {
        dp[1][1 << i][0] = 1;
        sums[1][1 << i][0] = i * st[cnt - 1] % INF;
    }
    dp[1][1 << num[0]][1] = 1;
    sums[1][1 << num[0]][1] = num[0] * st[cnt - 1] % INF;
    for (ll len = 2; len <= cnt; len++) {
        for (ll mask = 0; mask < M; mask++) {
            for (ll i = 0; i < 10; i++) {
                ll mask1 = mask | (1 << i);
                add(dp[len][mask1][0], dp[len - 1][mask][0]);
                add(sums[len][mask1][0], sums[len - 1][mask][0]);
                add(sums[len][mask1][0], dp[len - 1][mask][0] * i % INF * st[cnt - len] % INF);
                if (i < num[len - 1]) {
                    add(dp[len][mask1][0], dp[len - 1][mask][1]);
                    add(sums[len][mask1][0], sums[len - 1][mask][1]);
                    add(sums[len][mask1][0], dp[len - 1][mask][1] * i % INF * st[cnt - len] % INF);
                } else if (i == num[len - 1]) {
                    add(dp[len][mask1][1], dp[len - 1][mask][1]);
                    add(sums[len][mask1][1], sums[len - 1][mask][1]);
                    add(sums[len][mask1][1], dp[len - 1][mask][1] * i % INF * st[cnt - len] % INF);
                }
            }
        }
    }
    for (ll i = 0; i < M; i++) {
        ll d = __builtin_popcount(i);
        if (d <= k) {
            add(res, sums[cnt][i][0]);
            add(res, sums[cnt][i][1]);
        }
    }
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    init();
    ll l, r, k;
    cin >> l >> r >> k;
    cout << (calc(r, k) - calc(l - 1, k) + INF) % INF<< "\n";
}