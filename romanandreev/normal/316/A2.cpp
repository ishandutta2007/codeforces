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
char s[1000000];
int cnt[1000];
ll cnk[100][100];
ll f[100];
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%s", s);
    int n = strlen(s);
    ll ans = 1;
    int c = 0;
    int c0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i == 0) {
                ans *= 9;
            } else {
                c0++;
            }
        } else 
        if (!(s[i] >= '0' && s[i] <= '9')) {
            if (cnt[s[i] - 'A'] == 0) {
                c++;
            }
            cnt[s[i] - 'A'] = 1;
        }
    }
    for (int i = 0; i <= 20; i++) {
        cnk[i][0] = 1;
        f[i] = (i == 0) ? 1 : (f[i - 1] * i);
        for (int j = 1; j <= i; j++) {
            cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
        }
    }
    if (c > 10) {
        ans = 0; 
    } else 
    if (s[0] >= 'A' && s[0] <= 'Z') {
        ans *= cnk[10][c] * f[c] - cnk[9][c - 1] * f[c - 1];
    } else {
        ans *= cnk[10][c] * f[c];
    }    
    printf("%I64d", ans);
    if (ans != 0){
        for (int i = 0; i < c0; i++) {
            printf("0");
        }
    }
    printf("\n");
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}