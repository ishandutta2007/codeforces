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
int a[1000000];
int b[1000000];
int c[1000000];
int n;
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        a[i] = i;
        b[i] = (i + 1) % n;
        c[i] = (a[i] + b[i]) % n;
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], " \n"[i + 1 == n]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", b[i], " \n"[i + 1 == n]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", c[i], " \n"[i + 1 == n]);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}