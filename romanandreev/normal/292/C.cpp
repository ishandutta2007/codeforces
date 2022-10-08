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
int r[100];
int was[100];
int cnt;
vi v;
bool goodd(char* s, int n, int ff) {
    int tk = 0;
    if (n == 0 || (n > 1 && s[0] == '0')) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        tk = tk * 10 + s[i] - '0';
        was[s[i] - '0'] = cnt;
    }
    v[ff] = tk;
    return tk >= 0 && tk < 256;
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        r[x] = 1;
    }
    vector<vi > ans;
    char ss[100];
    int R;
    v.pb(0);
    v.pb(0);
    v.pb(0);
    v.pb(0);

    for (int i = 4; i <= 12; i++) {
        int stp = (i + 1) / 2;
        int pw = 1;
        for (int j = 0; j < stp; j++) {
            pw = pw * 10;
        }
        for (int j = 0; j < pw; j++) {            
            int tk = j;
            R = 0;
            bool good = true;
            for (int k = 0; k < stp; k++) {
                int ff = tk % 10;
                if (r[ff] == 0) {
                    good = false;
                    break;
                }
                ss[R++] = '0' + ff;
                tk /= 10; 
            }
            if (!good) continue;
            for (int k = i / 2 - 1; k >= 0; k--) {
                ss[R++] = ss[k];
            }
            ss[R] = 0;
            cnt++;
         //   cerr<<ss<<endl;
            for (int i1 = 0; i1 < min(3, R); i1++) if (goodd(ss + 0, i1 + 1, 0))
            for (int i2 = i1 + 1; i2 < min(i1 + 4, R); i2++) if (goodd(ss + i1 + 1, i2 - i1, 1))
            for (int i3 = i2 + 1; i3 < min(i2 + 4, R); i3++) if (goodd(ss + i2 + 1, i3 - i2, 2)){
                if (R - i3 - 1 > 3) continue;
                if (goodd(ss + i3 + 1, R - 1 - i3, 3)) {
                    bool can = true;
                    for (int t = 0; t < 10; t++) {
                        if ((was[t] != cnt && r[t] == 1) || (was[t] == cnt && r[t] == 0)) {
                            can = false;
                            break;
                        }
                    }
                    if (can) {
                        ans.pb(v);
                    }
                }
            }
            
        }
    }
/*    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            if (good(i) && good(j)) {
                string s0 = go(i) + go(j);
                string s1 = s0;
                int ss = sz(s0);
                for (int k = ss - 1; k >= 0; k--) {
                    s1 += s1[k];
                }
                for (int t = ss + 1; t < 2 * ss; t++) {
                    int i1 = obr(s1, ss, t);
                    int j1 = obr(s1, t, 2 * ss);
                    if (good(i1) && good(j1) && supergood(i, j, i1, j1)) {
                        ans.pb(mp(mp(i, j), mp(i1, j1)));
                    }
                }
                for (int c = 0; c < 10; c++) {
                    s1 = s0;
                    s1 += c + '0';
                    for (int k = ss - 1; k >= 0; k--) {
                        s1 += s1[k];
                    }
                    for (int t = ss + 1; t <= 2 * ss; t++) {
                        int i1 = obr(s1, ss, t);
                        int j1 = obr(s1, t, 2 * ss + 1);
                        if (good(i1) && good(j1) && supergood(i, j, i1, j1)) {
                            ans.pb(mp(mp(i, j), mp(i1, j1)));
                        }
                    }    
                }
            }
        }
    }                  */
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
        printf("%d.%d.%d.%d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}