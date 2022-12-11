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

set<int, greater<int>> s;
bool relax(int d) {
    if (d == 0)
        return false;
    if (s.count(d) == 0)
        return true;

    int nxt = d / 2;
    if (relax(nxt)) {
        s.erase(d);
        s.insert(nxt);
        return true;
    } else {
        return false;
    }
}
int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    scanf("%d", &n);
    forn(i, n) {
        int d;
        scanf("%d", &d);
        s.insert(d);
    }
    while(true) {
        if (!relax(*s.begin())) {
            break;
        }
    }
    for (auto i : s) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}