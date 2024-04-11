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
using ul = unsigned long long;
using ld = long double;
using namespace std;

const int N = 1 << 18, MOD = 1e9 + 7;
ll pw[N];

struct f {
    ll h;
    int c1, c2, c;

    f operator+(f x) {
        f res;
        if (c == 0 && x.c == 0)
            return {0, c1 ^ x.c1, 0, 0};
        if (x.c == 0)
            return {h, c1, c2 ^ x.c1, c};
        if (c == 0)
            return {x.h, c1 ^ x.c1, x.c2, x.c};
        return {((h * 2 + (c2 ^ x.c1)) * pw[x.c - 1] + x.h) % MOD, c1, x.c2, c + x.c};
    }

    bool operator==(f x) {
        return h == x.h && c1 == x.c1 && c2 == x.c2 && c == x.c;
    }

    void print() {
        cout << h << ' ' << c1 << ' ' << c2 << ' '  << c << '\n';
    }
};

f tr[N * 2];

f sum(int cl, int cr, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl)
        return {0, 0, 0, 0};
    if (cl <= l && r <= cr)
        return tr[v];
    return sum(cl, cr, v * 2, l, (l + r) / 2) + sum(cl, cr, v * 2 + 1, (l + r) / 2, r);
}


int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    pw[0] = 1;
    rep(i, N - 1)
        pw[i + 1] = pw[i] * 2 % MOD;
    int n;
    string s;
    cin >> n >> s;
    rep(i, n) {
        if (s[i] == '0')
            tr[N + i] = {0, 0, 0, 1};
        else
            tr[N + i] = {0, 1, 0, 0};
    }
    for (int i = N - 1; i > 0; i--)
        tr[i] = tr[i * 2] + tr[i * 2 + 1];
    int q, p1, p2, d;
    cin >> q;
    rep(i, q) {
        cin >> p1 >> p2 >> d;
        p1--; p2--;
        if (sum(p1, p1 + d) == sum(p2, p2 + d))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}