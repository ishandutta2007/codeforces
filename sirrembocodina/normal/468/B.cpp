#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int x[100100], p[100100], sz[100100], c[100100];
map<int, int> m;
bool ok = true;

int rt(int v) {
    return p[v] == -1 ? v : (p[v] = rt(p[v]));
}

void merge_s(int a, int b) {
    a = rt(a);
    b = rt(b);
    if (a == b) {
        return;
    }
    if (c[b] && c[a] && c[b] != c[a]) {
        ok = false;
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    sz[a] += sz[b];
    p[b] = a;
    if (c[b]) {
        c[a] = c[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    forn (i, n) {
        cin >> x[i];
        m[x[i]] = i;
        p[i] = -1;
        sz[i] = 1;
    }
    forn (i, n) {
        if (m.find(a - x[i]) == m.end()) {
            if (c[rt(i)] == 1) {
                ok = false;
            }
            c[rt(i)] = 2;
        } else {
            merge_s(i, m[a - x[i]]);
        }
        if (m.find(b - x[i]) == m.end()) {
            if (c[rt(i)] == 2) {
                ok = false;
            }
            c[rt(i)] = 1;
        } else {
            merge_s(i, m[b - x[i]]);
        }
    }
    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    forn (i, n) {
        cout << max(0, c[rt(i)] - 1) << ' ';
    }
    cout << endl;
    return 0;
}