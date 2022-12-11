#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1100;

string s[MAXN];

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    cin.sync_with_stdio(false);
    cin >> n;
    forn(i, n)
        cin >> s[i];
    if (n == 1) {
        cout << 6 << '\n';
        return 0;
    }
    int mx = 0;
    forn(i, n)
        forn(j, i) {
            int c = 0;
            forn(k, 6)
                if (s[i][k] == s[j][k])
                    c++;
            mx = max(mx, c);
        }
    cout << max(0, (6 - mx - 1) / 2);
    return 0;
}