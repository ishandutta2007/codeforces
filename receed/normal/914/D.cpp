#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;

const int mx = 1 << 19;
int t[mx * 2];

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

void upd(int v) {
    t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    if (v > 1)
        upd(v / 2);
}

int q1(int v, int l, int r, int cl, int x) {
    if (r <= cl || t[v] % x == 0)
        return r;
    if (r - l == 1)
        return l;
    int m = (l + r) / 2;
    int w1 = q1(v * 2, l, m, cl, x);
    if (w1 < m)
        return w1;
    return q1(v * 2 + 1, m, r, cl, x);
}

int q2(int v, int l, int r, int cr, int x) {
    if (cr <= l || t[v] % x == 0)
        return l - 1;
    if (r - l == 1)
        return l;
    int m = (l + r) / 2;
    int w1 = q2(v * 2 + 1, m, r, cr, x);
    if (m <= w1)
        return w1;
    return q2(v * 2, l, m, cr, x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cq, l, r, x, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[mx + i];
    for (int i = mx - 1; i > 0; i--)
        t[i] = gcd(t[i * 2], t[i * 2 + 1]);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> cq;
        if (cq == 1) {
            cin >> l >> r >> x;
            if (q2(1, 0, mx, r + 1, x) - q1(1, 0, mx, l, x) <= 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else {
            cin >> l >> x;
            t[mx + l] = x;
            upd((mx + l) / 2);
        }
    }
}