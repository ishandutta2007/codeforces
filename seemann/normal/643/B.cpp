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
const int MAXN = 1100;


int p[MAXN];
int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, k;
    int a, b, c, d;
    scanf("%d%d", &n, &k);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (n == 4 || k < n + 1) {
        cout << -1 << '\n';
        return 0;
    }
    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    p[1] = a;
    p[2] = c;
    p[n - 1] = d;
    p[n] = b;
    s.erase(a);
    s.erase(b);
    s.erase(c);
    s.erase(d);
    int j = 3;
    for (auto x : s) {
        p[j++] = x;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", p[i]);
    printf("\n");
    swap(p[1], p[2]);
    swap(p[n - 1], p[n]);
    for (int i = 1; i <= n; ++i)
        printf("%d ", p[i]);
    printf("\n");





    return 0;
}