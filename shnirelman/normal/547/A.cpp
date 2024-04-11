#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 1e6 + 13;

/*
*/

int p1[N], p2[N];

int d1[N], d2[N];

int a, b, c, d;

void dfs1(int v, int to, int deep) {
    if(v == to) {
        a = deep;
    }

    d1[v] = deep;
    int u = p1[v];

    if(d1[u] != -1) {
        b = d1[v] - d1[u] + 1;
        if(d1[u] > d1[to]) {
            b = -1;
        }
    } else {
        dfs1(u, to, deep + 1);
    }
}

void dfs2(int v, int to, int deep) {
    if(v == to) {
        c = deep;
    }

    d2[v] = deep;
    int u = p2[v];

    if(d2[u] != -1) {
        d = d2[v] - d2[u] + 1;
        if(d2[u] > d2[to]) {
            d = -1;
        }
    } else {
        dfs2(u, to, deep + 1);
    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int m;
    cin >> m;

    int fr1, to1, x1, y1;
    cin >> fr1 >> to1 >> x1 >> y1;

    int fr2, to2, x2, y2;
    cin >> fr2 >> to2 >> x2 >> y2;

    for(int i = 0; i < m; i++) {
        p1[i] = (x1 * 1ll * i + y1) % m;
        p2[i] = (x2 * 1ll * i + y2) % m;
        d1[i] = d2[i] = -1;
    }

    a = b = c = d = -1;

    dfs1(fr1, to1, 0);
    dfs2(fr2, to2, 0);

//    cout << a << ' ' << b << ' ' <<c <<' ' <<d  << endl;
    if(a == -1 || c == -1) {
        cout << -1 << endl;
        return 0;
    }

    if(b == -1 && d == -1) {
        cout << (a == c && a != -1 ? a : -1) << endl;
        return 0;
    }

    if(b == -1) {
        cout << (((a - c) % d == 0 && a != -1 && c != -1 && a >= c ? a : -1));
        return 0;
    }

    if(d == -1) {
        cout << (((c - a) % b == 0 && a != -1 && c != -1 && c >= a ? c : -1));
        return 0;
    }

    for(int i = 0; i < m * 5; i++) {
        if(a - c + b * 1ll * i >= 0 && (a - c + b * 1ll * i) % d == 0) {
            cout << a + b * 1ll * i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}