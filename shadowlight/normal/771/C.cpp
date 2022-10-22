#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <vector <ll> > gr;
ll n, k;

ll ans = 0;

void dfs(ll v, ll p, vector <ll> &cnt, vector <ll> &dp) {
    for (ll u : gr[v]) {
        if (u == p) continue;
        vector <ll> cnt1(k, 0), dp1(k, 0);
        dfs(u, v, cnt1, dp1);
        vector <ll> dp2(k, 0), cnt2(k, 0);
        for (ll i = 0; i < k - 1; i++) {
            dp2[i + 1] = dp1[i];
            cnt2[i + 1] = cnt1[i];
        }
        dp2[0] = dp1[k - 1] + cnt1[k - 1];
        cnt2[0] = cnt1[k - 1];
        for (ll i = 0; i < k; i++) {
            for (ll j = 0; j < k; j++) {
                if (i + j == 0) {
                    ans += dp[i] * cnt2[j] + dp2[j] * cnt[i];
                } else if (i + j > k) {
                    ans += dp[i] * cnt2[j] + dp2[j] * cnt[i] + 2 * cnt[i] * cnt2[j];
                } else {
                    ans += cnt[i] * cnt2[j] + dp[i] * cnt2[j] + dp2[j] * cnt[i];
                }
            }
        }
        /*if (u == 1) {
            for (ll i = 0; i < k; i++) {
                cout << dp2[i] << " ";
            }
            cout << endl;
            for (ll i = 0; i < k; i++) {
                cout << cnt2[i] << " ";
            }
            cout << endl;
        }*/
        for (ll i = 0; i < k; i++) {
            ans += dp2[i];
            if (i != 0) ans += cnt2[i];
            dp[i] += dp2[i];
            cnt[i] += cnt2[i];
        }
    }
    cnt[0]++;
    /*cout << ans << endl;
    cout << v << endl;
    for (ll i = 0; i < k; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    for (ll i = 0; i < k; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;*/
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    gr.resize(n);
    for (ll i = 1; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        gr[l].push_back(r);
        gr[r].push_back(l);
    }
    vector <ll> cnt(k, 0), dp(k, 0);
    dfs(0, -1, cnt, dp);
    cout << ans;
}