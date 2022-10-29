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
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int N = 1000 * 1000 + 5;
int n, m, a[N];

int l[N], r[N], ans[N];
vector <int> req[N];

bool read() {
    if (scanf("%d %d", &n, &m) != 2)
        return false;

    forn(i, n)
        scanf("%d", &a[i]);

    forn(i, m) {
        scanf("%d %d", &l[i], &r[i]);
        --l[i], --r[i];
        req[ l[i] ].pb(i);
    }
    return true;
}

int ft[N];

void update(int pos, int val) {
    for (; pos < N; pos |= (pos + 1))
        ft[pos] = min(ft[pos], val);
}

const int INF = 1e9;

int get(int r) {
    int res = INF;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res = min(res, ft[r]);
    return res;
}

void solve() {
    map <int, int> last;

    forn(i, N)
        ft[i] = INF;

    for (int i = n - 1; i >= 0; --i) {
        if (last.count(a[i])) {
            int j = last[a[i]];
            update(j, j - i);
        }

        last[a[i]] = i;

        forn(j, sz(req[i])) {
            int id = req[i][j];
            ans[id] = get(r[id]);

            if (ans[id] > INF / 2)
                ans[id] = -1;
        }
    }

    forn(i, m)
        printf("%d\n", ans[i]);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    while (read())
        solve();
    
    return 0;
}