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

const ld INF = 1e18L;
const ld EPS = 1e-4;
const ld PI = acos(-1.0L);
const int MAXN = 1e5 + 100;

int n, p;
int a[MAXN], b[MAXN];
bool check(ld t) {
    ld sum = 0;
    forn(i, n) {
        sum += max(0.0L, (t * a[i] - b[i]));
    }
//    cerr << fixed << setprecision(20)<< sum << '\n';
//    cerr << fixed << setprecision(20)<< p * t << '\n';
//    cerr << sum - p * t << '\n';
    return sum <= p * t;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin >> n >> p;
    ll suma = 0;
    forn(i, n) {
        cin >> a[i] >> b[i];
        suma += a[i];
    }
    if (suma <= p) {
        cout << -1 << '\n';
        return 0;
    }
//    cerr << check(1e10 + 1) << '\n';
//    return 0;
    ld l = 0, r = INF;
    forn(_, 300) {
        ld m = (l + r) / 2;
        if (check(m)){
            l = m;
        } else{
            r = m;
        }
    }
    cout << fixed << setprecision(20) << l << '\n';
    


    return 0;
}