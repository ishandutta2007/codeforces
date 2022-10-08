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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int M = 100 - 35;
int a[2][M + 1][M + 1];
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    int tk = 0;
    a[tk][0][0] = n;
    while (1) {        
        memset(a[1 - tk], 0, sizeof(a[1 - tk]));
        bool good = false;
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= M; j++) if (a[tk][i][j]){
                if (a[tk][i][j] >= 4) {
                    good = true;
                    for (int k = 0; k < 4; k++) if (i + dx[k] >= 0 && j + dy[k] >= 0) {
                        if (i > 0 && i + dx[k] == 0) {
                            a[1 - tk][i + dx[k]][j + dy[k]]++;
                        }
                        if (j > 0 && j + dy[k] == 0) {
                            a[1 - tk][i + dx[k]][j + dy[k]]++;
                        }                        
                        a[1 - tk][i + dx[k]][j + dy[k]]++;
                    }
                    a[1 - tk][i][j] += a[tk][i][j] - 4;
                } else {
                    a[1 - tk][i][j] += a[tk][i][j];
                }
            }
        }
        tk = 1 - tk;
        if (!good) break;
    }
  /*  int M1 = 10;
    for (int i = -M1; i <= M1; i++) {
        for (int j = -M1; j <= M1; j++) {
            cerr<<a[tk][abs(i)][abs(j)]<<" ";
        }
        cerr<<endl;
    }*/
    int m, x, y;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        if (abs(x) > M  || abs(y) > M) printf("0\n"); else
        printf("%d\n", a[tk][abs(x)][abs(y)]);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}