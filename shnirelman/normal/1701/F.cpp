#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 30;
const int L = 2001;

int t[N];

void add(int i, int x) {
    for(; i < N; i |= i + 1)
        t[i] += x;
}

int get(int i) {
    int res = 0;
    for(; i > 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

int get(int l, int r) {
    return get(r - 1) - get(max(0, l - 1));
}

li s1[N * 4], s11[N * 4], d[N * 4], cnt[N * 4];

//li get(int v, int l, int r, int ql)

//pli merge(pli a, pli b) {
//    pli c(a.f + b.f, a.s * b.f + b.s * a.f);
//    return c;
//}

void push(int v, int l, int r) {
    int v1 = v * 2 + 1, v2 = v * 2 + 2;
    int m = (l + r) / 2;

    d[v1] += d[v];
    d[v2] += d[v];

    s11[v1] += s1[v1] * 1ll * (cnt[v1] - 1) * 2ll * d[v] + cnt[v1] * 1ll * (cnt[v1] - 1) * d[v] * d[v];
    s11[v2] += s1[v2] * 1ll * (cnt[v2] - 1) * 2ll * d[v] + cnt[v2] * 1ll * (cnt[v2] - 1) * d[v] * d[v];

    s1[v1] += d[v] * cnt[v1];
    s1[v2] += d[v] * cnt[v2];




    d[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int x) {
//    if(v == 0)
//        cout << "start update " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << x << endl;
    if(l >= qr || r <= ql)
        return;

    if(ql <= l && r <= qr) {
        d[v] += x;
        s11[v] += s1[v] * 1ll * (cnt[v] - 1) * 2ll * x + cnt[v] * 1ll * (cnt[v] - 1) * x * x;
        s1[v] += cnt[v] * 1ll * x;

//        s11[v] += (r - l) * (r - l - 1);
//        cout << "end update " << v << ' ' << l << ' ' << r << ' ' << cnt[v] * 1ll * x << "    " << s1[v] << ' ' << s11[v] << endl;
        return;
    }

    push(v, l, r);

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);

    cnt[v] = cnt[v * 2 + 1] + cnt[v * 2 + 2];
    s1[v] = s1[v * 2 + 1] + s1[v * 2 + 2];
    s11[v] = s11[v * 2 + 1] + s11[v * 2 + 2] + s1[v * 2 + 1] * s1[v * 2 + 2] * 2;
//    cout << "updtae " << v << ' ' << l << ' ' << r << ' ' << s1[v] << "   |   " <<
//    s1[v * 2 + 1] << ' ' << s1[v * 2 + 2] << ' ' << cnt[v * 2 + 1] << ' ' << cnt[v * 2 + 2] << endl;
//    s11[v] = (m - l == 1 ? s1[v * 2 + 1] : s11[v * 2 + 1]) * s1[v * 2 + 2] +
//            (r - m == 1 ? s1[v * 2 + 2] : s11[v * 2 + 2]) * s1[v * 2 + 1];

//    pli res = merge(pli(s1))
}

void add(int v, int l, int r, int i, int x, bool fl) {
    if(r - l == 1) {
        d[v] = 0;
        if(fl) {
            cnt[v] = 1;
            s1[v] = x;
        } else {
            cnt[v] = 0;
            s1[v] = 0;
        }
        return;
    }

    push(v, l, r);

    int m = (l + r) / 2;

    if(i < m)
        add(v * 2 + 1, l, m, i, x, fl);
    else
        add(v * 2 + 2, m, r, i, x, fl);

    cnt[v] = cnt[v * 2 + 1] + cnt[v * 2 + 2];
    s1[v] = s1[v * 2 + 1] + s1[v * 2 + 2];
    s11[v] = s11[v * 2 + 1] + s11[v * 2 + 2] + s1[v * 2 + 1] * s1[v * 2 + 2] * 2;
}

bool b[N];

/*
3 5
8 5 3
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    update(0, 0, N, 1, 5, 1);
//    cout << s1[0] << endl;
//    update(0, 0, N, 1, 5, 1);
//    cout << s1[0] << endl;

    int q, d;
    cin >> q >> d;

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if(b[x]) {
            b[x] = false;
            add(x, -1);

            update(0, 0, N, x + 1, min(N, x + d + 1), -1);
            add(0, 0, N, x, 0, false);
//            update(0, 0, N, x, x + 1, -get(x - d, x));
        } else {
            update(0, 0, N, x + 1, min(N, x + d + 1), 1);
//            cout << "s1 = " << s1[0] << "  s11 = " << s11[0] << endl;
            add(0, 0, N, x, get(x - d, x), true);
//            update(0, 0, N, x, x + 1, get(x - d, x));

            b[x] = true;
            add(x, 1);
        }

//        cout << "s1 = " << s1[0] << "  s11 = " << s11[0] << endl;

        li res = (s1[0] * (s1[0] - 1) - s11[0]) / 2;
        cout << res << '\n';
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}