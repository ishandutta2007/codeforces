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
const int MAXN = 25;

int a[MAXN][MAXN];
int n, m;

bool check(vector<int> & p) {
    forn(i, n) {
        int d = 0;
        forn(j, m) {
            if (a[i][j] != p[j])
                d++;
        }
        if (d > 2)
            return false;

    }
    return true;

}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin >> n >> m;
    forn(i, n) {
        forn(j, m) {
            cin >> a[i][j];
        }
    }
    vector<int> p(m);
    forn(i, m)
        p[i] = i + 1;

    if (check(p)) {
        printf("YES\n");
        return 0;
    }
    forn(i, m) {
        forn(j, i) {
            swap(p[i], p[j]);
            if (check(p)) {
                printf("YES\n");
                return 0;
            }
            swap(p[i], p[j]);
        }
    }
    printf("NO\n");

    return 0;
}