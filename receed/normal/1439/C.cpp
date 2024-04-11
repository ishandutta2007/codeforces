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

const int N = 1 << 18;
ll ts[N * 2], tmn[N * 2], mod[N * 2];

void rel(int v) {
    ts[v] = ts[v * 2] + ts[v * 2 + 1];
    tmn[v] = min(tmn[v * 2], tmn[v * 2 + 1]);
}

void push(ll v, ll l, ll r) {
    if (!mod[v])
        return;
    ts[v] = mod[v] * (r - l);
    tmn[v] = mod[v];
    if (v < N) {
        mod[v * 2] = mod[v];
        mod[v * 2 + 1] = mod[v];
    }
    mod[v] = 0;
}

int getf(ll x, int v=1, int l=0, int r=N) {
    push(v, l, r);
    if (tmn[v] > x)
        return -1;
    if (r - l == 1)
        return l;
    int res = getf(x, v * 2, l, (l + r) / 2);
    if (res != -1)
        return res;
    return getf(x, v * 2 + 1, (l + r) / 2, r);
}

void tset(ll cl, ll cr, ll x, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(v, l, r);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[v] = x;
        push(v, l, r);
        return;
    }
    push(v, l, r);
    tset(cl, cr, x, v * 2, l, (l + r) / 2);
    tset(cl, cr, x, v * 2 + 1, (l + r) / 2, r);
    rel(v);
}

pair<ll, ll> gs(ll cl, ll x, ll v=1, ll l=0, ll r=N) {
    push(v, l, r);
    if (r <= cl || tmn[v] > x) {
        return {x, 0};
    }
    if (cl <= l && ts[v] <= x) {
        return {x - ts[v], r - l};
    }
    auto p1 = gs(cl, x, v * 2, l, (l + r) / 2);
    auto p2 = gs(cl, p1.first, v * 2 + 1, (l + r) / 2, r);
    p2.second += p1.second;
    return p2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q, t, x, y;
    cin >> n >> q;
    rep(i, n) {
        cin >> ts[N + i];
        tmn[N + i] = ts[N + i];
    }
    for (int i = N - 1; i > 0; i--)
        rel(i);
    rep(i, q) {
        cin >> t >> x >> y;
        if (t == 1) {
            ll pos = getf(y);
            tset(pos, x, y);
        }
        else {
            cout << gs(x - 1, y).second - (N - n) << '\n';
        }
    }
}