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
int n, m;
int deg[1000000];
int cnt[1000000];
int x, y ,mx;
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        x--, y--;
        deg[x]++;
        deg[y]++;       
    }
    if (m < n - 1 || m > n) {
        printf("unknown topology\n");
        return 0;
    }
    mx = 0;
    for (int i = 0; i < n; i++) {
        cnt[deg[i]]++;
        mx = max(mx, deg[i]);
    }
    if (mx == 2 && m == n && cnt[2] == n) {
        printf("ring topology\n");
        return 0;
    }
    if (mx == n - 1 && m == n - 1 && cnt[1] == n - 1 && cnt[mx] == 1) {
        printf("star topology\n");
        return 0;
    }
    if (m == n - 1 && mx == 2 && cnt[1] == 2 && cnt[2] == n - 2) {
        printf("bus topology\n");
        return 0;
    }
    printf("unknown topology\n");
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}