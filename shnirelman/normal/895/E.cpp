#include <bits/stdc++.h>

using namespace std;
using li = long long;
using ld = long double;

const int N = 1e5 + 13;

int a[N];
ld sum[N * 4], add[N * 4], mul[N * 4];

void build(int v, int l, int r) {
    mul[v] = 1;
    add[v] = 0;
    if(r - l == 1) {
        sum[v] = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}

void push(int v, int l, int r) {
    int m = (l + r) / 2;
    int v1 = v * 2 + 1;
    int v2 = v * 2 + 2;

    sum[v1] *= mul[v];
    sum[v2] *= mul[v];

    add[v1] *= mul[v];
    add[v2] *= mul[v];

    mul[v1] *= mul[v];
    mul[v2] *= mul[v];

    sum[v1] += add[v] * (m - l);
    sum[v2] += add[v] * (r - m);

    add[v1] += add[v];
    add[v2] += add[v];

    add[v] = 0;
    mul[v] = 1;
}

void upd_add(int v, int l, int r, int ql, int qr, ld x) {
//    cout << "add " << x << endl;
    if(l >= qr || r <= ql)
        return;

    if(ql <= l && r <= qr) {
        sum[v] += x * (r - l);
        add[v] += x;
        return;
    }

    push(v, l, r);

    int m = (l + r) / 2;

    upd_add(v * 2 + 1, l, m, ql, qr, x);
    upd_add(v * 2 + 2, m, r, ql, qr, x);

    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}

void upd_mul(int v, int l, int r, int ql, int qr, ld x) {
//    cout << "mul " << x << endl;
    if(l >= qr || r <= ql)
        return;

    if(r - l == 1) {
        add[v] = 0;
        mul[v] = 1;
    } else {
        push(v, l, r);
    }

    if(ql <= l && r <= qr) {
        mul[v] = x;
        sum[v] *= x;
        return;
    }

    int m = (l + r) / 2;

    upd_mul(v * 2 + 1, l, m, ql, qr, x);
    upd_mul(v * 2 + 2, m, r, ql, qr, x);

    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}

ld get(int v, int l, int r, int ql, int qr) {
    if(l >= qr || r <= ql)
        return 0;

    if(ql <= l && r <= qr) {
        return sum[v];
    }

    push(v, l, r);

    int m = (l + r) / 2;

    return get(v * 2 + 1, l, m, ql, qr) + get(v * 2 + 2, m, r, ql, qr);
}

void write(int v, int l, int r) {
    cout << v << ' ' << l << ' ' << r << ' ' << sum[v] << ' '<< add[v] << ' ' << mul[v] << endl;
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    write(v * 2 + 1, l, m);
    write(v * 2 + 2, m, r);
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n);

    cout << setprecision(20) << fixed;

    for(int i = 0; i < q; i++) {
        int qr;
        cin >> qr;

        if(qr == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            l1--;
            l2--;

            ld sum1 = get(0, 0, n, l1, r1);
            ld sum2 = get(0, 0, n, l2, r2);

            int len1 = r1 - l1;
            int len2 = r2 - l2;

//            cout << sum1 << ' ' << sum2 << endl;
//            cout << "mul " << ld(len1 - 1) / len1 << ' ' << ld(len2 - 1) / len2 << endl;

            upd_mul(0, 0, n, l1, r1, ld(len1 - 1) / len1);
            upd_mul(0, 0, n, l2, r2, ld(len2 - 1) / len2);

//            cout << sum1 << ' ' << sum2 << endl;
//            sum1 = get(0, 0, n, l1, r1);
//            sum2 = get(0, 0, n, l2, r2);
//            cout << sum1 << ' ' << sum2 << endl;

            upd_add(0, 0, n, l1, r1, sum2 / len2 / len1);
            upd_add(0, 0, n, l2, r2, sum1 / len1 / len2);

//            cout << "add " << sum2 / len2 << ' ' << sum1 / len1 << endl;

//cout << sum1 << ' ' << sum2 << endl;
//            sum1 = get(0, 0, n, l1, r1);
//            sum2 = get(0, 0, n, l2, r2);
//            cout << sum1 << ' ' << sum2 << endl;
        } else {
            int l, r;
            cin >> l >> r;

            cout << get(0, 0, n, l - 1, r) << endl;
        }

//        write(0, 0, n);
    }
}