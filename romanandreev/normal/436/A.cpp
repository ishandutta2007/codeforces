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
int n, x;
int t[3000];
int h[3000];
int m[3000];
int was[3000];

int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &t[i], &h[i], &m[i]);
    }
    int ans = 0;
    for (int start = 0; start <= 1; start++) {
        int h0 = x;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            was[i] = 0;
        }
        int cur = start;
        while (1) {            
            int mx = -1;
            for (int i = 0; i < n; i++) {
                if (was[i] == 0 && t[i] == cur && h[i] <= h0) {
                    if (mx == -1 || m[i] > m[mx]) {
                        mx = i;
                    }
                }
            }
            if (mx == -1) {
                break;
            }
            was[mx] = 1;
            sum++;
            h0 += m[mx];
            cur ^= 1;
        }
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    return 0;
}