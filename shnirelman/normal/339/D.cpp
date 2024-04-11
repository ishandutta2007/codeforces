#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17) + 13;

int a[N];
int t[N * 4];

int calc(int x, int y, bool fl) {
    if(fl)
        return (x | y);
    else
        return (x ^ y);
}

void build(int v, int l, int r, bool fl) {
    if(r - l == 1) {
        t[v] = a[l];
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m, !fl);
    build(v * 2 + 2, m, r, !fl);

    t[v] = calc(t[v * 2 + 1], t[v * 2 + 2], fl);
}

void upd(int v, int l, int r, bool fl, int i, int x) {
//    cout << "upd " << v <<  ' ' << l << ' ' << r << ' ' << t[v] << endl;
    if(r - l == 1) {
        t[v] = x;
        return;
    }

    int m = (l + r) / 2;

    if(i < m)
        upd(v * 2 + 1, l, m, !fl, i, x);
    else
        upd(v * 2 + 2, m, r, !fl, i, x);



   t[v] = calc(t[v * 2 + 1], t[v * 2 + 2], fl);
//cout << "upd " << v <<  ' ' << l << ' ' << r << ' ' << t[v] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i  =0; i < (1 << n); i++) {
        cin >> a[i];
    }

    build(0, 0, 1 << n, n % 2);

    for(int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;

        upd(0, 0, 1 << n, n % 2, p - 1, x);

        cout << t[0] << '\n';
    }

}