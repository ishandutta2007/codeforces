//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int t[4 * N], d[4 * N];

void push(int v) {
    t[v * 2 + 1] += d[v];
    t[v * 2 + 2] += d[v];
    d[v * 2 + 1] += d[v];
    d[v * 2 + 2] += d[v];
    d[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int x) {
    if(l >= qr || r <= ql)
        return;

    if(ql <= l && r <= qr) {
        t[v] += x;
        d[v] += x;
        return;
    }

    push(v);

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);

    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int l, int r) {
    if(r - l == 1)
        return l;

    push(v);
    int m = (l + r) / 2;

    if(t[v * 2 + 2] >= 1)
        return get(v * 2 + 2, m, r);
    else
        return get(v * 2 + 1, l, m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n, -1);
    set<int> push, pop;

    for(int i = 0; i < n; i++) {
        int pos, tp;
        cin >> pos >> tp;

        pos--;

        if(tp == 0) {
            update(0, 0, n, 0, pos + 1, -1);
        } else {
            int x;
            cin >> x;

            a[pos] = x;

            update(0, 0, n, 0, pos + 1, 1);
        }

        cout << (t[0] < 1 ? -1 : a[get(0, 0, n)]) << '\n';
    }


}