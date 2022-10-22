#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 4e5 + 13;
const int LOGN = 30;

int M;

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}


int a[N];
int t[N * 4];
int nw[N * 4];

void push(int v, int l, int r) {
    if(nw[v] == -1)
        return;

    int m = (l + r) / 2;
    t[v * 2 + 1] = (m - l) * nw[v];
    t[v * 2 + 2] = (r - m) * nw[v];

    nw[v * 2 + 1] = nw[v * 2 + 2] = nw[v];
    nw[v] = -1;
}

int get_sum(int v, int l, int r, int ql, int qr) {
    if(ql >= r || qr <= l)
        return 0;

    if(nw[v] != -1)
        return (nw[v] == 0 ? 0 : min(r, qr) - max(l, ql));

    if(ql <= l && r <= qr)
        return t[v];

//    push(v, l, r);

    int m = (l + r) / 2;

    return get_sum(v * 2 + 1, l, m, ql, qr) + get_sum(v * 2 + 2, m, r, ql, qr);
}

void update(int v, int l, int r, int ql, int qr, int qx) {
    if(ql >= r || qr <= l)
        return;

    if(ql <= l && r <= qr) {
        t[v] = (r - l) * qx;
        nw[v] = qx;
        return;
    }

    push(v, l, r);

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, qx);
    update(v * 2 + 2, m, r, ql, qr, qx);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int get(int v, int l, int r) {
//    cout << "get " << v << ' ' << l << ' ' << r << ' ' << t[v] << ' ' << nw[v] << endl;
    if(nw[v] == 1)
        return r - 1;

    if(r - l == 1) {
        return l;
    }

    int m = (l + r) / 2;

    if(t[v * 2 + 2] > 0)
        return get(v * 2 + 2, m, r);
    else
        return get(v * 2 + 1, l, m);
}


int get_add(int v, int l, int r, int ql, int qx) {
//    cout << "get_add " << v << ' ' << l << ' ' << r << ' ' << ql << ' '<< qx << endl;
    if(t[v] == (r - l) * qx || r <= ql)
        return -1;

    if(r - l == 1)
        return l;

    push(v, l, r);

    int m = (l + r) / 2;

//    if(ql > l) {
        int r1 = get_add(v * 2 + 1, l, m, ql, qx);
        if(r1 != -1)
            return r1;
        else
            return get_add(v * 2 + 2, m, r, ql, qx);
//    } else {
//        if((m - l) * qx == t[v * 2 + 1])
//            return get_add(v * 2 + 2, m, r, ql, qx);
//        else
//            return get_add(v * 2 + 1, l, m, ql, qx);
//    }
}

void add(int x) {
//    int l = x, r = N;
//    while(r - l > 1) {
//        int m = (l + r) / 2;
//
//        if(get_sum(0, 0, N, x, m) == m - x)
//            l = m;
//        else
//            r = m;
//    }
    int l = get_add(0, 0, N, x, 1);

//    cout << "add " << x << ' ' << l << endl;

    if(l > x)
        update(0, 0, N, x, l, 0);
    update(0, 0, N, l, l + 1, 1);
}

void sub(int x) {
//    int l = x, r = N;
//    while(r - l > 1) {
//        int m = (l + r) / 2;
//
//        if(get_sum(0, 0, N, x, m) == 0)
//            l = m;
//        else
//            r = m;
//    }

    int l = get_add(0, 0, N, x, 0);

//    cout << "sub " << x << ' ' << l << endl;

    if(l > x)
        update(0, 0, N, x, l, 1);
    update(0, 0, N, l, l + 1, 0);
}

/*
11 2
3 4 4 4 4 6 9 9 10 10 10
7 7
9 6

11 2
4 10 4 10 4 10 9 6 4 3 9
11 7
2 6
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4 * N; i++)
        nw[i] = -1;

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        add(a[i]);
    }

//    for(int i = 0; i < 13; i++)
//        cout << i << ' ' << get_sum(0, 0, N, i, i + 1) << endl;
//
//    cout << get(0, 0, N) << endl;
//
    for(int i = 0; i < q; i++) {
//        cout << i << endl;
        int k, l;
        cin >> k >> l;

        k--;

        sub(a[k]);

//        cout << "------------" << endl;
//        for(int i = 0; i < 13; i++)
//            cout << i << ' ' << get_sum(0, 0, N, i, i + 1) << endl;
//        cout << "------------" << endl;

        a[k] = l;
        add(a[k]);

//        cout << "------------" << endl;
//        for(int i = 0; i < 13; i++)
//            cout << i << ' ' << get_sum(0, 0, N, i, i + 1) << endl;
//        cout << "------------" << endl;

        cout << get(0, 0, N) << '\n';
//        cout << get_sum(0, 0, N, 11, 12) << endl;
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}