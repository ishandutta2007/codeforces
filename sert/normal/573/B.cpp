#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define m (l + r) / 2

const ll N = 1e6 + 34;
const ll INF = 1e9 + 34;

ll a[N], add[N], t[N];

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

void push(int v, int l, int r) {
    if (add[v] == 0)
        return;
    add[v * 2 + 1] += add[v];
    add[v * 2 + 2] += add[v];
    t[v * 2 + 1] += add[v];
    t[v * 2 + 2] += add[v];
    add[v] = 0;
}

ll sum(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r)
        return INF;
    if (L <= l && r <= R)
        return t[v];
    push(v, l, r);
    return min(sum(v * 2 + 1, l, m, L, R), sum(v * 2 + 2, m, r, L, R));
}

void setx(int v, int l, int r, int L, int R, ll x) {
    if (l >= R || L >= r)
        return;
    if (L <= l && r <= R) {
        add[v] += x;
        t[v] += x;
        return;
    }
    push(v, l, r);
    setx(v * 2 + 1, l, m, L, R, x);
    setx(v * 2 + 2, m, r, L, R, x);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    ll n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = min(i + 1ll, a[i]);
        a[i] = min(n - i, a[i]);
        a[i] += i;
    }
    build(0, 0, n);
    for (int i = 0; i < n; i++) {
        ans = max(ans, t[0]);
        //cout << t[0] << " ";
        setx(0, 0, n, 0, i + 1, 1);
        setx(0, 0, n, i + 1, n, -1);
    }
    //cout << "\n";
    cout << ans;
}