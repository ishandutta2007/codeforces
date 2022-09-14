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

const int N = 1 << 15, K = 15;
int pr[N], pw;
vector<pair<int, int>> res[N];
ll k, x, n, ts;
pair<int, int> ans[K];
map<ll, ll> mp;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    vector<vector<ll>> a(k);
    vector<ll> s(k);
    rep(i, k) {
        cin >> n;
        rep(j, n) {
            cin >> x;
            a[i].push_back(x);
            s[i] += x;
            ts += x;
            mp[x] = i;
        }
    }
    if (ts % k) {
        cout << "No";
        return 0;
    }
    ts /= k;
    pw = 1 << k;
    for (int i = 1; i < pw; i++)
        pr[i] = -1;
    rep(i, k)
        for (ll j : a[i]) {
            vector<int> used(k);
            vector<pair<int, int>> li;
            ll pos = i, d = ts - s[i] + j, d0 = d, ms = 0;
            while (!used[pos]) {
                ms |= 1 << pos;
                used[pos] = 1;
                li.push_back({d, pos});
                if (!mp.count(d)) {
                    pos = -1;
                    break;
                }
                pos = mp[d];
                d = ts - s[pos] + d;
            }
            if (pos == i && d == d0) {
                pr[ms] = ms;
                res[ms] = li;
            }
        }
    rep(i, pw)
        if (pr[i] == -1)
            for (int j = i; j; j = ((j - 1) & i))
                if (pr[j] == j && pr[i ^ j] != -1)
                    pr[i] = j;
    if (pr[pw - 1] == -1) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    int cm = pw - 1;
    while (cm) {
        int nm = pr[cm];
        for (int i = 0; i < res[nm].size(); i++)
            ans[res[nm][(i + 1) % res[nm].size()].second] = res[nm][i];
        cm ^= nm;
    }
    rep(i, k)
        cout << ans[i].first << ' ' << ans[i].second + 1 << '\n';
}