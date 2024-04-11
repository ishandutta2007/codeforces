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
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int n, l, r, x;
int a[16];

bool read() {
    if (!(cin >> n >> l >> r >> x))
        return false;
    forn (i, n) {
        cin >> a[i];
    }
    return true;
}

int ex(vector<int> &v, int d) {
    int res = v[0] * d;

    forn (i, v.size()) {
        if (v[i] * d > res)
            res = v[i] * d;
    }
    
    return res * d;
}

void solve() {
    int ans = 0;

    forn (i, 1 << n) {
        vector<int> cur;
        int sum = 0;
        int cnt = 0;

        forn (j, n) {
            if (i & (1 << j)) {
                cur.pb(a[j]);
                sum += a[j];
                cnt++;
            }
        }
        if (cnt > 1 && sum >= l && sum <= r) {
            if (ex(cur, 1) - ex(cur, -1) >= x)
                ans++;
        }
    }

    cout << ans << endl;
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