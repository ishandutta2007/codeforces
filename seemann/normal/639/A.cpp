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
const int MAXN = 2e5;

int t[MAXN];

struct _less {
    bool operator () (int a, int b) {
        if (t[a] != t[b])
            return t[a] > t[b];
        return a < b;
    }
};

set<int, _less> s;
int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    srand(time(NULL));
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    forn(i, n) {
        scanf("%d", &t[i]);
    }
    forn(i, q) {
        int tp, id;
        scanf("%d%d", &tp, &id);
        id--;
        if (tp == 1) {
            s.insert(id);
        } else {
            int cnt = 0;
            bool flag = false;
            for (auto p : s) {
                if (p == id) {
                    flag= true;
                    break;
                }
                cnt++;
                if (cnt == k)
                    break;
            }
            printf(flag ? "YES\n" : "NO\n");
        }
    }
    
    return 0;
}