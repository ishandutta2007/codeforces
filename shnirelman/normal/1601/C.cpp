#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
//const int M = 1e5 + 13;
const int A = 213;

/*
1
5
1 2 1 2 3
*/

int t[N * 4], d[N * 4];

void build(int v, int l, int r, int x) {
    d[v] = 0;
//    cout << "build " << v << ' ' <<l << ' ' << r << ' ' << x << endl;
    if(r - l == 1) {
        t[v] = x;

        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m, x);
    build(v * 2 + 2, m, r, x + m - l);



    t[v] = x;
}

void push(int v) {
    int v1 = v * 2 + 1;
    int v2 = v * 2 + 2;

    d[v1] += d[v];
    d[v2] += d[v];

    t[v1] += d[v];
    t[v2] += d[v];

    d[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int x) {
    if(ql >= r || qr <= l)
        return;

//    cout << "update1 " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << x << ' ' << t[v] << endl;
//    cout << t[v * 2 + 1] << ' ' << t[v * 2 + 2] << endl;

    if(ql <= l && r <= qr) {
        d[v] += x;
        t[v] += x;
        return;
    }

    int m = (l + r) / 2;

    push(v);

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);

    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);

//    cout << "update " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << x << ' ' << t[v] << endl;
//    cout << t[v * 2 + 1] << ' ' << t[v * 2 + 2] << endl;
}

int get(int v, int l, int r, int ql, int qr) {
    if(ql >= r || qr <= l)
        return INF;

    if(ql <= l && r <= qr)
        return t[v];

    push(v);

    int m = (l + r) / 2;

    int res = min(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m, r, ql, qr));

//    cout << "get " << v << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << res << endl;
//    return res;

    return min(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m, r, ql, qr));
}

int ft[N];

void add(int i, int x) {
    for(; i < N; i |= i + 1)
        ft[i] += x;
}

int get(int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += ft[i];
    return res;
}

/*
1
3 4
1 2 3
4 3 2 1

1
3 3
3 2 1
1 2 3
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    vector<pii> c(n);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = {a[i], i};
        mp[a[i]].push_back(i);
    }

    sort(c.begin(), c.end());

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    build(0, 0, n + 1, 0);

//    for(int i = 0; i < n * 4; i++) {
//        cout << "t " << i << ' ' << t[i] << ' ' << d[i] << endl;
//    }

    li ans = 0;

    int i = 0;
    for(int j = 0; j < m; j++) {
        if(j > 0 && b[j - 1] != b[j]) {
            while(i < n && c[i].f == b[j - 1]) {
//                cout << "upd " << c[i].s + 1 << ' ' << n << ' ' << -1 << endl;
//                update(0, 0, n + 1, c[i].s + 1, n + 1, -1);
//                cout << "upd " << 0 << ' ' << c[i].s + 1 << ' ' << 1 << endl;
                update(0, 0, n + 1, 0, c[i].s + 1, 1);
                i++;
            }
//            for(auto ind : mp[b[j - 1]]) {
//                cout << "upd " << 0 << ' ' << ind + 1 << ' ' << 1 << endl;
//                update(0, 0, n + 1, 0, ind + 1, 1);
//            }
        }

        while(i < n && c[i].f < b[j]) {
//            cout << "upd " << c[i].s + 1 << ' ' << n << ' ' << -1 << endl;
            update(0, 0, n + 1, c[i].s + 1, n + 1, -1);
//            cout << "upd " << 0 << ' ' << c[i].s + 1 << ' ' << 1 << endl;
            update(0, 0, n + 1, 0, c[i].s + 1, 1);
            i++;
        }

        if(j == 0 || j > 0 && b[j - 1] != b[j]) {
            for(auto ind : mp[b[j]]) {
//                cout << "upd " << ind + 1 << ' ' << n << ' ' << -1 << endl;
                update(0, 0, n + 1, ind + 1, n + 1, -1);
            }
        }

//        cout << "for " << j << ' ' << i << ' ' << get(0, 0, n + 1, 0, n + 1) << endl;

        ans += get(0, 0, n + 1, 0, n + 1);
    }

    vector<int> d = a;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    for(int i = 0; i < n; i++) {
        ft[i] = 0;
    }

    for(int i = n - 1; i >= 0; i--) {
//        cout << i << endl;
        a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        ans += (a[i] == 0 ? 0 : get(a[i] - 1));
//         cout << i << ' ' << a[i] << endl;
        add(a[i], 1);
    }

    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}