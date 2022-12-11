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
const int MAXN = 2e5 + 100;

int sa[MAXN], a[MAXN];
int sd[MAXN], d[MAXN];
int last[MAXN];
int p[MAXN];
int ord[MAXN];

bool cmp(int a, int b) {
    return last[a] < last[b];
}
int m;
bool check(int n) {
    forn(i, m) {
        a[i] = sa[i];
        last[i] = -1;
    }
    forn(i, n)
        d[i] = sd[i];
    forn(i, n) {
        if (d[i] >= 0) {
            last[d[i]] = i;
        }
    }
    forn(i, n) {
        if (d[i] >= 0 && last[d[i]] != i) {
            d[i] = -1;
        }
    }
    forn(i, m) {
        if (last[i] == -1)
            return false;
    }
    int k = 0;
    forn(i, n) {
        if (d[i] >= 0) {
            p[k++] = d[i];
        }
    }
    int cur = 0;
    forn(i, n) {
        if (d[i] < 0) {
            a[p[cur]]--;
            if (a[p[cur]] == 0) {
                cur++;
                if (cur == m)
                    return true;
            }
        } else {
            if (a[d[i]] > 0)
                return false;
        }
    }
    return true;
}


int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    forn(i, n) {
        cin >> sd[i];
        sd[i]--;
    }
    forn(i, m) {
        cin >> sa[i];
    }
    int l = 0, r = n + 1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (r >= n + 1) {
        cout << -1 << '\n';
    } else {
        cout << r << '\n';
    }

    return 0;
}