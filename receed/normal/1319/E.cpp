#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bitset>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using ld = long double;
using namespace std;

const int N = 1 << 20;
ll tr[N * 2], mod[N * 2];

void push(int v) {
    tr[v] += mod[v];
    if (v < N) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
    }
    mod[v] = 0;
}

void rel(int v) {
    tr[v] = max(tr[v * 2], tr[v * 2 + 1]);
}

void add(int cl, int cr, ll d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(v);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[v] += d;
        push(v);
        return;
    }
    push(v);
    add(cl, cr, d, v * 2, l, (l + r) / 2);
    add(cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(v);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<ll>> a(n, vector<ll>(2)), b(m, vector<ll>(2)), c(p, vector<ll>(3));
    rep(i, n)
        cin >> a[i][0] >> a[i][1];
    sort(rall(a));
    int pos = 0;
    ll mn = 1e10;
    for (int i = N - 1; i >= 0; i--) {
        while (pos < a.size() && a[pos][0] > i) {
            mn = min(mn, a[pos][1]);
            pos++;
        }
        tr[N + i] = -mn;
    }
    for (int i = N - 1; i > 0; i--)
        rel(i);
    rep(i, m)
        cin >> b[i][0] >> b[i][1];
    sort(all(b));
    rep(i, p)
        cin >> c[i][1] >> c[i][0] >> c[i][2];
    sort(all(c));
    ll ans = -1e10;
    pos = 0;
    for (auto &pp : b) {
        while (pos < c.size() && c[pos][0] < pp[0]) {
            add(c[pos][1], N, c[pos][2]);
            pos++;
        }
        ans = max(ans, -pp[1] + tr[1]);
    }
    cout << ans;
}