#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:16777216")

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
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const li INF64 = 1e18;
const ld EPS = 1e-9;

typedef pair<ld, ld> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int n, k;
const int N = 100005;
ld x[N];
ld y[N];

pt f;

void gen() {
    set<int> s;
    n = 4;
    forn (i, n) {
        x[i] = rand() % 20;
        if (s.count(x[i]))
            i--;
        else
            s.insert(x[i]);
    }
    k = rand() % n;
    f = mp(rand() % 20, rand() % 20);
    sort(x, x + n);
}

bool read() {
    //gen();
    //return true;
    if (!(cin >> n >> k))
        return false;
    k--;
    forn (i, n) {
        cin >> x[i];
    }
    cin >> f.x >> f.y;
    int st = x[k];
    sort(x, x + n);
    if (k == n) {
        ld ans1 = sqrt(sqr(x[0] - f.x) + sqr(f.y)) + x[n - 1] - x[0];
        ld ans2 = sqrt(sqr(x[n - 1] - f.x) + sqr(f.y)) + x[n - 1] - x[0];
        cout << fixed << setprecision(10) << min(ans1, ans2) << endl;
        exit(0);
    }
    forn (i, n)
        if (x[i] == st)
            k = i;
    return true;
}

ld dist(int v) {
    if (v < 0 || v >= n)
        return 0;
    return sqrt(sqr(f.x - x[v]) + sqr(f.y));
}

ld naive() {
    x[n] = f.x, y[n] = f.y;
    vector<int> v;
    forn (i, n + 1)
        v.pb(i);

    ld ans = INF;

    do {
        if (v[0] != k)
            continue;
        ld cur = 0;
        forn (i, n) {
            cur += sqrt(sqr(x[v[i]] - x[v[i + 1]]) + sqr(y[v[i]] - y[v[i + 1]]));
        }
        ans = min(ans, cur);
    } while(next_permutation(all(v)));

    return ans;
}

void solve() {

    ld ans = INF;   
    ld cur = 0;
    
    forn (i, n) {
        cur = x[k] - x[0] + x[i] - x[0];
        cur += dist(i);
        int r = max(i + 1, k + 1);
        if (r < n)
            cur += min(dist(r), dist(n - 1)) + x[n - 1] - x[r];
        ans = min(ans, cur);

        cur = x[n - 1] - x[k] + x[n - 1] - x[i];
        cur += dist(i);
        int l = min(i - 1, k - 1);
        if (l >= 0)
            cur += min(dist(0), dist(l)) + x[l] - x[0];
        ans = min(ans, cur);
    
        cur = abs(x[k] - x[i]) + x[i] - x[0];
        cur += dist(0);
        r = max(i + 1, k + 1);
        if (r < n)
            cur += min(dist(r), dist(n - 1)) + x[n - 1] - x[r];
        ans = min(ans, cur);

        cur = abs(x[i] - x[k]) + x[n - 1] - x[i];
        cur += dist(n - 1);
        l = min(i - 1, k - 1);
        if (l >= 0)
            cur += min(dist(0), dist(l)) + x[l] - x[0];
        ans = min(ans, cur);
    }

    /*if(fabs(ans - naive()) > EPS) {
        cout << "TEST" << endl;
        cout << naive() << ' ' << ans << endl;
        cout << n << ' ' << k << endl;
        forn (i, n)
            cout << x[i] << ' ';
        cout << f.x << ' ' << f.y << endl;
        exit(0);
    }*/
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
        
    while(read())
        solve();

    return 0;
}