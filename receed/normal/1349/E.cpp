#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200001;
ll a[N], z[N], pz[N], ans[N], dp[N][2], dj[N][2], dneed[N][2], pr[N][2];
ll n;

ll ss(ll l, ll r) {
    l = n - l; r = n - r;
    return (l + r) * (l - r + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> l;
    rep(i, n) {
        cin >> a[i];
        if (a[i])
            l.push_back(i);
        a[i]--;
    }
    rep(i, (int) l.size() - 1) {
        if (a[l[i]] == a[l[i + 1]] + 1) {
            for (int j = l[i]; j < l[i + 1]; j++)
                z[j] = 1;
        }
        else if (a[l[i]] == a[l[i + 1]]) {
            if (a[l[i]] == a[l.back()])
                z[l[i]] = z[l[i + 1]] = 1;
            else
                for (int j = l[i]; j <= l[i + 1]; j++)
                    z[j] = 1;
        }
    }
    vector<int> nl;
    for (int i : l)
        if (nl.empty() || a[i] > a[nl.back()])
            nl.push_back(i);
    l = nl;
    // for (int i : l)
    //     cout << i << ' ';
    // cout << '\n';
    rep(i, n + 1)
        pz[i + 1] = pz[i] + 1 - z[i];
    dp[0][0] = -1;
    dp[0][1] = n + 1;
    rep(i, l.size()) {
        dp[i + 1][0] = dp[i + 1][1] = n + 1;
        rep(t1, 2) {
            rep(t2, 2) {
                if (dp[i][t1] == n + 1)
                    continue;
                ll x = l[i], da = a[x] - (i == 0 ? 0 : a[l[i - 1]]) + t2 - t1, mr = n + 1, bj, mp = dp[i][t1];
                // cout << ' ' << t2 << ' ' << da << '\n';
                for (ll j = 0; j <= x - mp - 1; j++) {
                    ll rs = n - da + ss(mp + 1, mp + j), ls = n - da + ss(x - j, x - 1);
                    // cout << "!" << t2 << ' ' << ls << ' ' << rs << endl;
                    ls = max(ls, x + 1 - t2);
                    rs = min(rs, n);
                    if (ls <= rs && ls < mr && (pz[rs + 1] - pz[ls] || ls == x + 1 && !z[x])) {
                        mr = ls;
                        bj = j;
                    }
                }
                // cout << "  " << t2 << ' ' << mr << endl;
                if (t2 == 1 && (mr > x || z[x]))
                    continue;
                while (z[mr])
                    mr++;
                ll need = mr - n + da;
                ll fbj = bj, fneed = need;
                for (ll j = mp + 1; j < x; j++) {
                    if (n - j + ss(x - bj + 1, x - 1) <= need) {
                        need -= n - j;
                        bj--;
                    }
                }
                if (need == 0 && mr < dp[i + 1][t2]) {
                    dp[i + 1][t2] = mr;
                    pr[i + 1][t2] = t1;
                    dj[i + 1][t2] = fbj;
                    dneed[i + 1][t2] = fneed;
                }
            }
        }
        // cout << l[i] << ' ' << dp[i + 1][0] << ' ' << dp[i + 1][1] << endl;
    }
    int ct = (dp[l.size()][0] == n + 1 ? 1 : 0);
    assert(dp[l.size()][ct] < n + 1);
    for (int i = (int) l.size() - 1; i >= 0; i--) {
        ans[dp[i + 1][ct]] = 1;
        ll x = l[i], mp = dp[i][pr[i + 1][ct]], bj = dj[i + 1][ct];
        for (ll j = mp + 1; j < x; j++) {
            if (n - j + ss(x - bj + 1, x - 1) <= dneed[i + 1][ct]) {
                dneed[i + 1][ct] -= n - j;
                bj--;
                ans[j] = 1;
            }
        }
        ct = pr[i + 1][ct];
    }
    rep(i, n)
        cout << ans[i];
    cout << endl;
}