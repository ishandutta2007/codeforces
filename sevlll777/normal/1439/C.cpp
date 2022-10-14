#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int N = 262144;
typedef long long ll;

pair<ll, int> tree[4 * N + 77];
ll drd[4 * N + 77];
ll METKA[4 * N + 77];
vector<ll> kek;
int yakce = 0;

void push(int v) {
    if (METKA[v] == 0) return;
    if (2 * v + 2 <= 4 * N + 11) {
        METKA[2 * v + 1] = METKA[v];
        METKA[2 * v + 2] = METKA[v];
    }
    tree[v] = {METKA[v] * drd[v], METKA[v]};
    METKA[v] = 0;
}

ll sum(int v, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq || l >= r) return 0;
    if (l >= lq && r <= rq) return tree[v].first;
    int m = (l + r) / 2;
    push(v);
    push(2 * v + 1);
    push(2 * v + 2);
    return sum(2 * v + 1, l, m, lq, rq) + sum(2 * v + 2, m, r, lq, rq);
}

void mass_update(int v, int l, int r, int lq, int rq, int x) {
    if (l >= r || l >= rq || r <= lq) return;
    push(v);
    push(2 * v + 1);
    push(2 * v + 2);
    if (l >= lq && rq >= r) {
        METKA[v] = x;
        push(v);
        int v2 = (v - 1) / 2;
        while (v2 > 0) {
            tree[v2] = {tree[2 * v2 + 1].first + tree[2 * v2 + 2].first,
                        min(tree[2 * v2 + 1].second, tree[2 * v2 + 2].second)};
            v2 = (v2 - 1) / 2;
        }
        v2 = 0;
        tree[v2] = {tree[2 * v2 + 1].first + tree[2 * v2 + 2].first,
                    min(tree[2 * v2 + 1].second, tree[2 * v2 + 2].second)};
    } else {
        int m = (l + r) / 2;
        mass_update(2 * v + 1, l, m, lq, rq, x);
        mass_update(2 * v + 2, m, r, lq, rq, x);
    }

}

void build(int v, int l, int r) {
    if (l >= r) return;
    if (l + 1 == r) {
        if (yakce >= kek.size()) {
            tree[v] = {0, 1e10};
        } else {
            tree[v] = {kek[yakce], kek[yakce]};
        }
        drd[v] = 1;
        yakce++;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    drd[v] = drd[2 * v + 1] + drd[2 * v + 2];
    tree[v] = {tree[2 * v + 1].first + tree[2 * v + 2].first, min(tree[2 * v + 1].second, tree[2 * v + 2].second)};
}

int hhh(int v, int l, int r, ll y) {
    if (l >= r) return N;
    if (l + 1 == r) {
        return l;
    }
    push(v);
    push(2 * v + 1);
    int m = (l + r) / 2;
    if (tree[2 * v + 1].second > y) {
        return hhh(2 * v + 2, m, r, y);
    } else {
        return hhh(2 * v + 1, l, m, y);
    }
}

int spusk228(int v, int l, int r, ll Y) {
    if (l >= r) return N;
    if (l + 1 == r) return l;
    push(v);
    push(2 * v + 1);
    int m = (l + r) / 2;
    if (tree[2 * v + 1].first <= Y) {
        return spusk228(2 * v + 2, m, r, Y - tree[2 * v + 1].first);
    } else {
        return spusk228(2 * v + 1, l, m, Y);
    }
}

int spusk777(int v, int l, int r, ll y) {
    if (l >= r) return N;
    if (l + 1 == r) return l;
    push(v);
    push(2 * v + 1);
    int m = (l + r) / 2;
    if (tree[2 * v + 1].second >= y) {
        return spusk777(2 * v + 2, m, r, y);
    } else {
        return spusk777(2 * v + 1, l, m, y);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    kek = A;
    build(0, 0, N);
    while (q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            int l = spusk777(0, 0, N, y);
            mass_update(0, 0, N, l, x + 1, y);
        } else {
            ll y1 = y;
            ll ans = 0;
            while (y1 > 0 && x < n) {
                ll yy = y1 + sum(0, 0, N, 0, x);
                int l = min(n - 1, spusk228(0, 0, N, yy) - 1);
                if (l <= x - 1) {
                    x = hhh(0, 0, N, y1);
                } else {
                    ans += l - (x - 1);
                    y1 -= sum(0, 0, N, x, l + 1);
                    x = l + 1;
                }
            }
            cout << ans << '\n';
        }
    }
}