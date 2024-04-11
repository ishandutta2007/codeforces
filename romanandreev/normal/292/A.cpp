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
pi p[1000000];
int mx = 0;
int tk = 0;
int q[1000000];
int l = 0, r = 0;
int SZ = 0;
void go(int t) {
    int dx = t - tk;
    while (l < r && dx > 0) {
        int v = q[l];
        int mn = min(v, dx);
        q[l] -= mn;
        dx -= mn;
        SZ -= mn;
        if (q[l] == 0) {
            l++;
        }
    }
}
void obr() {
    while (l < r) {
        tk += q[l++];
    }
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = mp(x, y);
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        pi v = p[i];
        go(v.x);
        if (v.y > 0) {
            q[r++] = v.y;
            SZ += v.y;              
            mx = max(mx, SZ);
        }
        tk = v.x;
    }
    obr();
    printf("%d %d\n", tk, mx);
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}