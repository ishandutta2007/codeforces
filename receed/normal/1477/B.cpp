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
int tr[N * 2], mod[N * 2];

void push(int v, int l, int r) {
    if (!mod[v])
        return;
    if (v < N)
        mod[v * 2] = mod[v * 2 + 1] = mod[v];
    tr[v] = (r - l) * (mod[v] - 1);
    mod[v] = 0;
}
void rel(int v) {
    tr[v] = tr[v * 2] + tr[v * 2 + 1];
}

int sum(int cl, int cr, int v=1, int l=0, int r=N) {
    push(v, l, r);
    if (cr <= l || r <= cl)
        return 0;
    if (cl <= l && r <= cr)
        return tr[v];
    return sum(cl, cr, v * 2, l, (l + r) / 2) + sum(cl, cr, v * 2 + 1, (l + r) / 2, r);
}

void add(int cl, int cr, int d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(v, l, r);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[v] = d + 1;
        push(v, l, r);
        return;
    }
    push(v, l, r);
    add(cl, cr, d, v * 2, l, (l + r) / 2);
    add(cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t, n, q;
    string s1, s2;
    cin >> t;
    rep(z, t) {
        cin >> n >> q >> s1 >> s2;
        rep(i, n)
            add(i, i + 1, s2[i] - '0');
        vector<pair<int, int>> lq(q);
        rep(i, q) {
            cin >> lq[i].first >> lq[i].second;
            lq[i].first--;
        }
        reverse(all(lq));
        int f = 0;
        for (auto &pp : lq) {
            int cs = sum(pp.first, pp.second), cd = pp.second - pp.first;
            if (cs * 2 == cd) {
                f = 1;
                break;
            }
            if (cs * 2 < cd)
                add(pp.first, pp.second, 0);
            else
                add(pp.first, pp.second, 1);
        }
        rep(i, n)
            if (sum(i, i + 1) != s1[i] - '0')
                f = 1;
        if (f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}