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


int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> rem(n);
    forn(i, n - 1)
        rem[i] = k;
    ll sum = 0;
    forn(i, n) {
        cin >> a[i];
        if (i > 0) {
            rem[i - 1] -= a[i];
            if (rem[i - 1] > 0) {
                sum += rem[i - 1];
                a[i] += rem[i - 1];
            }
        }
        rem[i] -= a[i];
    }
    cout << sum << '\n';
    forn(i, n)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}