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

const int N = 81;
ll g[N][N], inf = 1e10, used[N], cv[N], ans = inf;
int n, k;
vector<pair<ll, ll>> d[N][N];

void go(int p) {
    if (p == k) {
        ll ca = 0;
        rep(i, k) {
            int p = 0;
            while (p < n && used[d[cv[i]][cv[i + 1]][p].second])
                p++;
            if (p == n)
                return;
            ca += d[cv[i]][cv[i + 1]][p].first;
        }
        ans = min(ans, ca);
        return;
    }
    rep(i, n) {
        used[i]++;
        cv[p] = i;
        go(p + 1);
        used[i]--;
    }
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    rep(i, n) {
        rep(j, n)
            cin >> g[i][j];
        g[i][i] = inf;
    }
    rep(i, n)
        rep(j, n) {
            rep(l, n)
                d[i][j].push_back({g[i][l] + g[l][j], l});
            sort(all(d[i][j]));
        }
    k /= 2;
    cv[0] = cv[k] = 0;
    go(1);
    cout << ans;
}