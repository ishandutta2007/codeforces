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
int n;
char s[3000000];
char t[3000000];
int c[2][2];
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d", &n);
    n *= 2;
    scanf("%s %s", s, t);
    for (int i = 0; i < n; i++) {
        c[s[i] - '0'][t[i] - '0']++;
    }
    vi s1;
    vi s2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int i1 = 1; i1 >= 0; i1--) {
                for (int j1 = 1; j1 >= 0; j1--) {
                    if (c[i1][j1] > 0) {
                        c[i1][j1]--;
                        s1.pb(i1);
                    //    s2.pb(j1);
                        goto a;
                    }
                }
            }
        } else {
            for (int i1 = 1; i1 >= 0; i1--) {
                for (int j1 = 1; j1 >= 0; j1--) {
                    if (c[j1][i1] > 0) {
                        c[j1][i1]--;
                        s2.pb(i1);
                  //      s2.pb(i1);
                        goto a;
                    }
                }
            }
        }
        a:;
    }
    if (s1 > s2) {
        printf("First\n");
    } else 
    if (s1 < s2) {
        printf("Second\n");
    } else {
        printf("Draw\n");
    }



    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}