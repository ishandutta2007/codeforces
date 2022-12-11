#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

int n;
int gss = 0;
void check(vector<int> g) {
    forn(k, 4) {
        assert(g[k] >= 1 && g[k] <= n);
    }
    assert(g[0] <= g[2] && g[1] <= g[3]);
}
int makeg(vector<int> g) {
    gss++;
    assert(gss <= 200);
    check(g);
    cout << "? ";
    forn(k, 4) {
        cout << g[k];
        if (k < 3)
            cout << ' ';
    }
    cout << '\n';
    cout.flush();
    int res = 0;
    cin >> res;
    return res;
}
int guess(int i, int c) {
    vector<int> g = {1, 1, n, n};
    int l, r;
    if (i < 2) {
        r = 1, l = n + 1;
    } else {
        r = n, l = 0;
    }
    while (int(abs(r - l)) != 1) {
        int m = (l + r) / 2;
        g[i] = m;
        if (makeg(g) >= c) {
            r = m;
        } else {
            l = m;
        }
    }
//    cout << i << ' ' << c << ' ' << r << '\n';
    return r;
}
int a[4][2];
int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin >> n;
    forn(i, 4)
        forn(j, 2)
            a[i][j] = guess(i, j + 1);

    
    forn(i, 2) {
        vector<int> g = {1, 1, n, n};
        if (a[i][0] <= a[2 + i][0]) {
            g[i] = a[i][0];
            g[2 + i] = a[2 + i][0];
            if (makeg(g) == 1) {
                swap(a[i][0], a[i][1]);
            }
        }
    }
    vector<vector<int>> r(2);
    forn(i, 2) {
        r[i] = {a[0][i], a[1][i], a[2][1 - i], a[3][1 - i]};
    }
    if (makeg(r[0]) == 0 || makeg(r[1]) == 0) {
        swap(r[0][1], r[1][1]);
        swap(r[0][3], r[1][3]);
    }
    assert(makeg(r[0]) == 1 && makeg(r[1]) == 1);
    cout << "! ";
    swap(r[0], r[1]);
    forn(i, 2) {
        check(r[i]);
        forn(j, 4) {
            cout << r[i][j];
            if (i < 1 || j < 3)
                cout << ' ';
        }
    }
    cout << endl;
    cout.flush();
    return 0;
}