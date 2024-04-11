#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef double ld;

typedef pair<ld, ld> pt;
#define ft first
#define sc second
#define x first
#define y second

int n;
const int N = 100 * 1000 + 5;
pt p[N];

bool read() {
    
    if (scanf("%d", &n) != 1)
        return false;
    forn (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i].x = x, p[i].y = y;
    }
    return true;
}

ld minv[N], maxv[N];

void calc() {
    minv[n] = 2e9, maxv[n] = -2e9;
    for (int i = n - 1; i >= 0; --i) {
        minv[i] = min(minv[i + 1], p[i].y);
        maxv[i] = max(maxv[i + 1], p[i].y);
    }
}

bool ok(ld s) {

    int rg = 0;
    ld gl = 2e9, gr = -2e9;
    forn (i, n) {
        while(rg < n && p[rg].x - p[i].x <= s)
            rg++;
        ld l = gl, r = gr;
        l = min(l, minv[rg]);
        r = max(r, maxv[rg]);
        if (r - l <= s)
            return true;
        gr = max(gr, p[i].y);
        gl = min(gl, p[i].y);
    }

    return false;
}

void solve() {
    forn (i, n) {
        pt np;
        np.x = p[i].x * cos(M_PI / 4) - p[i].y * sin(M_PI / 4);
        np.y = p[i].x * sin(M_PI / 4) + p[i].y * cos(M_PI / 4);
        p[i] = np;
    }

    sort(p, p + n);
        
    calc();

    ld l = 0, r = 2e9;

    forn (it, 50) {
        ld mid = (l + r) / 2;
        if (ok(mid))
            r = mid;
        else
            l = mid; 
    }

    cout << fixed << setprecision(10) << l / sqrt(2.0) << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

    while (read())
        solve();
    
    return 0;
}