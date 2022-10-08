#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
const int md = 1e9;
ll a[1000000];
ll f[1000000];
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % md;
    }
    for (int j = 0; j < m; j++) {
        int x, y, t;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d", &x, &y);
            a[x - 1] = y;
        } 
        if (t == 2) {
            scanf("%d %d", &x, &y);
            ll sum = 0;
            for (int i = x - 1; i <= y - 1; i++) {
                sum = (sum + f[i - (x - 1)] * a[i]) % md;
            }
            printf("%I64d\n", sum);
        } 
        if (t == 3) {
            int z;
            scanf("%d %d %d", &x, &y, &z);
            for (int i = x - 1; i <= y - 1; i++) {
                a[i] += z;
            }
        }

    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}