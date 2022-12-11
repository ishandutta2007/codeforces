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
const int MAXN = 1e5 + 100;

int a[MAXN];
ll pr[MAXN];

ll countsum(int l, int r) {
    if (r <= l + 1)
        return 0;
    return pr[r] - pr[l + 1];
}

int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    scanf("%d", &n);
    pr[0] = 0;
    forn(i, n) {
        scanf("%d", &a[i]);
        pr[i + 1] = pr[i] + a[i];
    }
    multiset<ll, greater<ll>> sums;
    sums.insert(pr[n]);
    set<int> del;
    del.insert(-1);
    del.insert(n);
    forn(i, n) {
        int d;
        scanf("%d", &d);
        d--;
        auto it = del.lower_bound(d);
        int r = *it;
        it--;
        int l = *it;
        sums.erase(sums.find(countsum(l, r)));
        del.insert(d);
        sums.insert(countsum(l, d));
        sums.insert(countsum(d, r));
        cout << (*sums.begin()) << '\n';
    }


    return 0;
}