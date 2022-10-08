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
const int MX = (int)2e5 + 5;
int n, m;
int a[MX];
int y[3000];
int dp0[101000];
int dp1[101000];
int sum[101000];
int wh[201000];
int wh2[201000];

int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &y[i]);
    }
    y[m++] = -1e9;
    y[m++] = 1e9;
    sort(y, y + m);
    vector<pair<int, int> > ls;
    for (int i = 0; i < MX - 1; i++) {
        if (a[i] == 0 && a[i + 1] == 1) {
            int tk = i + 1;
            while (a[tk] == 1) {
                tk++;
            }
            ls.pb(mp(i + 1, tk - 1));
        }
    }
    n = sz(ls);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + ls[i - 1].y - ls[i - 1].x + 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = sum[i]; j < sum[i + 1]; j++) {
            wh[j] = i;
        }
        for (int j = sum[i] + 1; j <= sum[i + 1]; j++) {
            wh2[j] = i;
        }
    }

    for (int i = 0; i <= n; i++) {
        dp0[i] = 0;
        dp1[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int p1 = lower_bound(y, y + m, ls[i].x) - y;
        int p2 = upper_bound(y, y + m, ls[i].y) - y;
        int curi;
        {
            int cc = p2 - p1;
            dp1[i + 1] = max(dp1[i + 1], cc + dp0[i]);
            for (int j = p1 - 1; j >= 0; j--) {
                cc++;
                int need = ls[i].x - y[j];
                if (need <= sum[i]) {
                    curi = wh[sum[i] - need];
                    dp1[i + 1] = max(dp1[i + 1], cc + dp0[curi]);
                }
            }
        }
        {
            int cc = 0;
            dp0[i + 1] = max(dp0[i + 1], cc + dp1[i + 1]);
            for (int j = p2; j < m; j++) {
                cc++;
                int need = y[j] - ls[i].y;                
                if (need <= sum[n] - sum[i + 1]) {
                    curi = wh2[sum[i + 1] + need];
                    dp0[curi + 1] = max(dp0[curi + 1], cc + dp1[i + 1]);
                }
            }
        }
//        cerr<<dp0[i]<<" "<<dp1[i]<<endl;
    }    
    cout<<dp0[n]<<endl;
//    cerr<<clock() * 1. / CLOCKS_PER_SEC<<endl;
    return 0;
}