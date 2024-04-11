#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n, m, k, w;
char a[1010][12][12];
int d0[1010];
int d[1010][1010];
int was[1010];
int bc[1010];
const int inf = 1e9;
int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    scanf("%d %d %d %d", &n, &m, &k, &w);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", a[i][j]);
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int cnt = 0;
            for (int i1 = 0; i1 < n; i1++) {
                for (int j1 = 0; j1 < m; j1++) {
                    cnt += (a[i][i1][j1] != a[j][i1][j1]);
                }
            }
            d[i][j] = d[j][i] = min(cnt * w, n * m);
        }
        d[i][k] = d[k][i] = n * m;
    }
    for (int i = 0; i <= k; i++) {
        d0[i] = inf;
        was[i] = 0;
        bc[i] = -1;
    }
    d0[k] = 0;
    vector<pair<int, int> > ls;
    int ans = 0;
    for (int it = 0; it <= k; it++) {
        int mn = -1;
        for (int i = 0; i <= k; i++) {
            if (was[i] == 0 && (mn == -1 || d0[mn] > d0[i]))  {
                mn = i;
            }
        }
        assert(mn != -1);
        was[mn] = 1;
        ans += d0[mn];
        if (mn < k) {
            ls.pb(mp(mn + 1, (d0[mn] == n * m ? 0 : bc[mn] + 1)));
//            printf("%d %d\n", mn + 1, (d0[mn] == n * m ? 0 : bc[mn] + 1));
        }
        for (int i = 0; i <= k; i++) if (was[i] == 0) {
            if (d0[i] > d[mn][i]) {
                d0[i] = d[mn][i];
                bc[i] = mn;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < k; i++) {
        printf("%d %d\n", ls[i].x, ls[i].y);
    }
    return 0;
}