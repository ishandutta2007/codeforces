#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18 + 7;
const ll o5 = 716327852;
const int N = 1e6 + 34;

ll t[N];

void add(int v, int l, int r, int p, ll x) {
    if (l + 1 == r) {
        t[v] = max(t[v], x);
        return;
    }
    int m = (l + r) / 2;
    if (p < m)
        add(v * 2 + 1, l, m, p, x);
    else
        add(v * 2 + 2, m, r, p, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

ll gmax(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r)
        return -INF;
    if (L <= l && r <= R)
        return t[v];
    int m = (l + r) / 2;
    return max(gmax(v * 2 + 1, l, m, L, R), gmax(v * 2 + 2, m, r, L, R));
}

ll b[N], lst;
pair <ll, ll> a[N];
ll d[N], n, h, r;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r >> h;
        a[i] = make_pair(h * r * r, i);
    }
    sort(a, a + n);
    b[0] = a[0].first;
    a[0].first = 0;
    swap(a[0].first, a[0].second);

    for (int i = 1; i < n; i++) {
        if (a[i].first == b[lst])
            a[i].first = lst;
        else {
            lst++;
            b[lst] = a[i].first;
            a[i].first = lst;
        }
        swap(a[i].first, a[i].second);
    }
    sort(a, a + n);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        d[i] = b[a[i].second] + (!!i) * gmax(0, 0, n, 0, a[i].second);
        add(0, 0, n, a[i].second, d[i]);
        ans = max(ans, d[i]);
    }

    cout.precision(10);
    cout << fixed << atan2l(0, -1) * ans;

}