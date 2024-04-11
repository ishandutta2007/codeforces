/**
 *    author:  [itmo] enot.1.10
 *    created: 28.03.2016 20:51:31       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 2e5 + 10;

int t[N];
int p[N];

inline int comp(int x, int y)
{
    ll v1 = t[x] * (ll)p[y];
    ll v2 = t[y] * (ll)p[x];
    if (v1 != v2) return v1 < v2;
    return p[x] < p[y];
}


int a[N];
dbl pnt[N];

pi pp[N];
int p1[N];

dbl mn[N];
dbl mx[N];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d", p + i);
    forn(i, n) scanf("%d", t + i);    
    dbl ST = 0;
    forn(i, n) ST += t[i];
    forn(i, n) a[i] = i;
    forn(i, n) pp[i] = mp(p[i], i);
    sort(pp, pp + n);
    forn(i, n) p1[pp[i].S] = i;

    sort(a, a + n, comp);
    dbl l = 0, r = 1;
    forn(_, 100)
    {
        dbl m = (l + r) * 0.5;
        int paradoks = 0;

        dbl T = 0;
        forn(i, n)
        {
            int x = a[i];
            int j = i + 1;
            while (j < n)
            {
                int y = a[j];
                if (p[x] * (ll)t[y] == p[y] * (ll)t[x]) ++j;
                else break;
            }
            dbl addT = 0;
            for (int k = i; k < j; ++k) addT += t[a[k]];
            for (int k = i; k < j; ++k)
            {
                dbl mn2 = p[a[k]] * (1 - m / ST * (T + addT));
                dbl mx2 = p[a[k]] * (1 - m / ST * (T + t[a[k]]));
                mn[p1[a[k]]] = mn2;
                mx[p1[a[k]]] = mx2;
            }
            T += addT;
            i = j - 1;
        }
        if (_ == 99)
        {
            eprintf("c = %.10f\n", m);
            forn(i, n) eprintf("%.10f %.10f (%d %d)\n", mn[i], mx[i], pp[i].F, pp[i].S);
        } 
        dbl mxx = -1e100;
        forn(i, n)
        {
            int j = i + 1;
            while (j < n && pp[j].F == pp[i].F) ++j;
            dbl mnn = 1e100;
            for (int k = i; k < j; ++k) mnn = min(mnn, mn[k]);
            if (mxx > mnn) paradoks = 1;
            for (int k = i; k < j; ++k) mxx = max(mxx, mx[k]);
            i = j - 1;
        }
        if (paradoks) r = m;
        else l = m;
    }
    printf("%.10f\n", l);       
                
            
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}