#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const ll N = 3e5 + 34;

ll d[N], h[N];
ll t[N * 2][2];
ll c[N][2];
ll n;

void add(int v, int l, int r, int p, ll x, int num) {
    if (l + 1 == r) {
        t[v][num] = x;
        return;
    }
    int m = (l + r) / 2;
    if (p < m)
        add(v * 2 + 1, l, m, p, x, num);
    else
        add(v * 2 + 2, m, r, p, x, num);
    ll r1 = c[t[v * 2 + 1][num]][num];
    ll r2 = c[t[v * 2 + 2][num]][num];
    if (r1 > r2)
        t[v][num] = t[v * 2 + 1][num];
    else
        t[v][num] = t[v * 2 + 2][num];
}

ll getmax(int v, int l, int r, int L, int R, int num) {
    if (l >= R || L >= r)
        return 2 * n;
    if (L <= l && r <= R)
        return t[v][num];
    int m = (l + r) / 2;
    ll i1 = getmax(v * 2 + 1, l, m, L, R, num);
    ll i2 = getmax(v * 2 + 2, m, r, L, R, num);
    ll r1 = c[i1][num];
    ll r2 = c[i2][num];
    if (r1 > r2)
        return i1;
    else
        return i2;
}

ll sum, num, a, b, m, i1, i2, res;
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%I64d %I64d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%I64d", &d[i]);
    for (int i = 0; i < n; i++) scanf("%I64d", &h[i]);

    for (int i = 0; i < N * 2; i++)
        t[i][0] = t[i][1] = n * 2;
    c[n * 2][0] = c[n * 2][1] = -INF;

    for (int i = 0; i < n * 2; i++) {
        c[i][0] = sum + 2 * h[i % n];
        c[i][1] = 2 * h[i % n] - sum;
        add(0, 0, 2 * n, i, i, 0);
        add(0, 0, 2 * n, i, i, 1);
        sum += d[i % n];
    }

    while (m--) {
        scanf("%I64d %I64d", &a, &b);
        a--;
        b--;
        if (a <= b)
            a += n;
        b++;
        //cerr << b << " " << a << " ba\n";
//        cerr << getmax(0, 0, 2 * n, b, a, 0) << " " << getmax(0, 0, 2 * n, b, a, 1) << "\n";
        i1 = getmax(0, 0, 2 * n, b, a, 0);
        i2 = getmax(0, 0, 2 * n, b, a, 1);
        if (i1 != i2)
            res = c[i1][0] + c[i2][1];
        else {
            res = max(c[getmax(0, 0, 2 * n, b, i1, 0)][0], c[getmax(0, 0, 2 * n, i1 + 1, a, 0)][0]) + c[i2][1];
            res = max(res, c[i1][0] + max(c[getmax(0, 0, 2 * n, b, i2, 1)][1], c[getmax(0, 0, 2 * n, i2 + 1, a, 1)][1]));
        }
        printf("%I64d\n", res);
    }

    /*for (int i = 0; i < 2 * n; i++)
        cerr << getmax(0, 0, 2 * n, i, i + 1, 0) << " ";
    cerr << "\n";

    for (int i = 0; i < 2 * n; i++)
        cerr << getmax(0, 0, 2 * n, i, i + 1, 1) << " ";
    cerr << "\n";*/

    return 0;
}