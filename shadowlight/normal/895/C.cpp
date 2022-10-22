#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = (1 << 11);
const int MAXK = 71;
const double EPS = 1e-8;
const int MAXL = 1e5 + 7;

vector <int> p;

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
    for (int i = 2; i <= 35; i++) {
        bool fl = 0;
        for (int j : p) {
            if (i % j == 0) {
                fl = 1;
                break;
            }
        }
        if (!fl) {
            p.push_back(i);
        }
    }
    vector <int> cnt(MAXK, 0);
    int n;
    cin >> n;
    vector <int> masks(n, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int mask = 0;
        for (int i = 0; i < (int) p.size(); i++) {
            while (x % p[i] == 0) {
                mask ^= (1 << i);
                x /= p[i];
            }
        }
        if (x != 1) {
            cnt[x]++;
        } else {
            masks[i] = mask;
        }
    }
    vector <int> dp(MAXN, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (masks[i] == -1) continue;
        vector <int> ndp(MAXN, 0);
        for (int j = 0; j < MAXN; j++) {
            ndp[j] += dp[j];
            if (ndp[j] >= INF) {
                ndp[j] -= INF;
            }
            ndp[j ^ masks[i]] += dp[j];
            if (ndp[j ^ masks[i]] >= INF) {
                ndp[j ^ masks[i]] -= INF;
            }
        }
        dp = ndp;
    }
    vector <ll> st(MAXL, 1);
    for (int i = 1; i < MAXL; i++) {
        st[i] = 2 * st[i - 1];
        if (st[i] >= INF) {
            st[i] -= INF;
        }
    }
    ll ans = dp[0];
    for (int i = 0; i < MAXK; i++) {
        if (!cnt[i]) continue;
        ans = ans * st[cnt[i] - 1] % INF;
    }
    cout << ans - 1;
}