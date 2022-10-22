//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2000000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*
1
8 5
2 1 7 4
4 2

*/

int t[4 * N], d[4 * N];

void push(int v) {
    d[v * 2 + 1] += d[v];
    d[v * 2 + 2] += d[v];
    t[v * 2 + 1] += d[v];
    t[v * 2 + 2] += d[v];
    d[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int x) {
    if(r <= ql || l >= qr)
        return;

//    if(v == 0)
//        cout << "update " << ql << ' ' << qr << ' ' << x << endl;

    if(ql <= l && r <= qr) {
        d[v] += x;
        t[v] += x;
        return;
    }


    push(v);
    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);

    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int l, int r, int ql, int qr) {
    if(r <= ql || l >= qr)
        return INF;

    if(ql <= l && r <= qr) {
        return t[v];
    }

    push(v);
    int m = (l + r) / 2;

    return min(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n, m;
    cin >> n >> m;

    vector<pair<int, pii>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].s.f >> a[i].s.s >> a[i].f;
        a[i].s.f--;
    }

    sort(a.begin(), a.end());

//    cout << endl;
//    for(int i = 0; i < n; i++) {
//        cout << a[i].f << ' ' << a[i].s.f << ' ' << a[i].s.s << endl;
//    }

    int ans = INF;
    int r = 0;
    int m1 = m * 2 - 1;

    for(int l = 0; l < n; l++) {
        while(r < n && get(0, 0, m1, 0, m1) == 0) {
            update(0, 0, m1, a[r].s.f * 2, a[r].s.s * 2 - 1, 1);
//            cout << endl;
            r++;
        }

//        cout << l << ' ' << r << ' ' << get(0, 0, m, 0, m) << endl;
        if(get(0, 0, m1, 0, m1) > 0) {
            ans = min(ans, a[r - 1].f - a[l].f);
        }

        update(0, 0, m1, a[l].s.f * 2, a[l].s.s * 2 - 1, -1);
//        cout << endl;
    }

    cout << ans << endl;
}