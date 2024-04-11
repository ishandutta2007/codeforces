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
const int md = 1e9 + 7;
int n, m;
const int maxn = (int)1e5 + 1;
int cnk[maxn + 104][104];
int sum[104][maxn + 2];

void add(int& x, int y) {
    x += y;
    if (x >= md) {
        x -= md;
    }
}
int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sum[0][i]);
    }
    for (int i = 0; i <= n + 101; i++) {
        cnk[i][0] = 1;
        for (int j = 1; j <= min(i, 101); j++) {
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % md;
        }
    }
    for (int i = 0; i < m; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        l--, r--;
        int lvl = 0;
        int shft = 0;
        while (k >= 0 && l <= r) {        
            lvl++;
            add(sum[lvl][l], cnk[k + shft][k]);
            add(sum[lvl][r + 1], md - cnk[k + r - l + shft][k]);
            l++;
            k--;
            shft++;
        }
    }    
    for (int i = 102; i >= 0; i--) {
        for (int j = 1; j < n; j++) {
            add(sum[i + 1][j], sum[i + 1][j - 1]);
        }
        for (int j = 0; j < n; j++) {
            add(sum[i][j], sum[i + 1][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", sum[0][i], " \n"[i + 1 == n]);
    }
//    cerr<<clock() * 1. / CLOCKS_PER_SEC<<endl;
    return 0;
}