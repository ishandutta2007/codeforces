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
const int md0 = 1e9 + 7;
const int md1 = 1e9 + 9;
int len0, n;
int len[11];
ll h0[1000000];
ll h1[1000000];
ll stp0[1000000];
ll stp1[1000000];
char ss[11][100000];
vector<ll> ls[11];
int l[11];
int r[11];
int cnt(vector<ll> & a, ll x) {
    return lower_bound(all(a), x + 1) - lower_bound(all(a), x);
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%s", s);
    len0 = strlen(s);
    stp0[0] = stp1[0] = 1;
    stp0[1] = stp1[1] = 239;
    for (int i = 2; i <= 1000000; i++) {
        stp0[i] = (stp0[i - 1] * stp0[1]) % md0;
        stp1[i] = (stp1[i - 1] * stp1[1]) % md1;
    }

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", ss[i], &l[i], &r[i]);
        len[i] = strlen(ss[i]);
        h0[len[i]] = 0;
        h1[len[i]] = 0;
        for (int j = len[i] - 1; j >= 0; j--) {
            h0[j] = (h0[j + 1] * stp0[1] + ss[i][j]) % md0;
            h1[j] = (h1[j + 1] * stp1[1] + ss[i][j]) % md1;
        }
        for (int j = 0; j < len[i]; j++) {
            for (int k = j; k < len[i]; k++) {
                ls[i].pb((h0[j] - (h0[k + 1] * stp0[k - j + 1]) % md0 + md0) % md0 + (ll)md0 * ((h1[j] - (h1[k + 1] * stp1[k - j + 1]) % md1 + md1) % md1));
            }
        }
        sort(all(ls[i]));
    }
    h0[len0] = 0;
    h1[len0] = 0;
    for (int i = len0 - 1; i >= 0; i--) {
        h0[i] = (h0[i + 1] * stp0[1] + s[i]) % md0;
        h1[i] = (h1[i + 1] * stp1[1] + s[i]) % md1;
    }
    set<ll> S;
    for (int j = 0; j < len0; j++) {
        for (int k = j; k < len0; k++) {
            ll ff = (h0[j] - (h0[k + 1] * stp0[k - j + 1]) % md0 + md0) % md0 + (ll)md0 * ((h1[j] - (h1[k + 1] * stp1[k - j + 1]) % md1 + md1) % md1);
//            cerr<<j<<" "<<k<<" "<<ff<<endl;
            bool good = true;
            for (int i = 0; i < n; i++) {
                int gg = cnt(ls[i], ff);
//                cerr<<j<<" "<<k<<" "<<i<<" "<<gg<<endl;
                if (!(gg >= l[i] && gg <= r[i])) {
                    good = false;
                    break;
                }
            }
            if (good) {
                S.insert(ff);
            }
        }
    }
    cout<<sz(S)<<endl;
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}