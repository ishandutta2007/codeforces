#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(), x.end()
// #define int long long
#define ld long double
using namespace std;
const int N = 262144;

int tree[4 * N + 77];
int METKA[4 * N + 77];
int sz[4 * N + 77];
vector<int> kek;
int yakce = 0;

void push(int v) {
    if (METKA[v] == -1) return;
    if (2 * v + 2 <= 4 * N + 11) {
        METKA[2 * v + 1] = METKA[v];
        METKA[2 * v + 2] = METKA[v];
    }
    if (METKA[v] == 0) {
        tree[v] = 0;
    } else {
        tree[v] = sz[v];
    }
    METKA[v] = -1;
}

int sum(int v, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq || l >= r) return 0;
    push(v);
    push(2 * v + 1);
    push(2 * v + 2);
    if (l >= lq && r <= rq) return tree[v];
    int m = (l + r) / 2;
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
        push(2 * v + 1);
        push(2 * v + 2);
        int v2 = (v - 1) / 2;
        while (v2 > 0) {
            tree[v2] = tree[2 * v2 + 1] + tree[2 * v2 + 2];
            v2 = (v2 - 1) / 2;
        }
        v2 = 0;
        tree[v2] = tree[2 * v2 + 1] + tree[2 * v2 + 2];
    } else {
        int m = (l + r) / 2;
        mass_update(2 * v + 1, l, m, lq, rq, x);
        mass_update(2 * v + 2, m, r, lq, rq, x);
    }

}

void build(int v, int l, int r) {
    if (l >= r) return;
    push(v);
    push(2 * v + 1);
    push(2 * v + 2);
    if (l + 1 == r) {
        if (yakce >= kek.size()) {
            tree[v] = 0;
        } else {
            tree[v] = kek[yakce];
        }
        sz[v] = 1;
        yakce++;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    sz[v] = sz[2 * v + 1] + sz[2 * v + 2];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> qq;
        yakce = 0;
        int n, q;
        string s, f;
        cin >> n >> q >> s >> f;
        int N0 = 1;
        while (N0 <= n) {
            N0 *= 2;
        }
        kek = {};
        mass_update(0, 0, N0, 0, N0, 0);
        for (auto c : f) kek.pb(c - '0');
        bool can = true;
        build(0, 0, N0);
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            qq.pb({l, r});
        }
        reverse(all(qq));
        for (auto p : qq) {
            int l = p.first, r = p.second;
            int len = r - l + 1;
            int cnt0 = len - sum(0, 0, N0, l, r + 1);
            if (cnt0 * 2 == len) {
                can = false;
            } else if (cnt0 * 2 > len) {
                mass_update(0, 0, N0, l, r + 1, 0);
            } else {
                mass_update(0, 0, N0, l, r + 1, 1);
            }
        }
        if (can) {
            for (int i = 0; i < n; i++) {
                if (sum(0, 0, N0, i, i + 1) != s[i] - '0') {
                    can = false;
                    break;
                }
            }
        }
        if (can) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}