/* -- ITMO UNIVERSITY 1 ---*/
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
#include <queue>

#define fs first
#define sc second
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

static inline unsigned long long rdtsc() { unsigned long long d; __asm__ __volatile__ ("rdtsc" : "=A" (d) ); return d; }

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

#define TASK "1"

const int N = 2;
int mod;

struct matrix
{   
    int a[N][N];

    matrix()
    {
        memset(a, 0, sizeof a);
    }

    matrix(int x)
    {
        memset(a, 0, sizeof a);
        forn(i, N) a[i][i] = x;
    }

    inline void out()
    {
        eprintf("---\n");
        forn(i, N) forn(j, N) eprintf("%d%c", a[i][j], " \n"[j + 1 == N]);
    }
};

inline matrix operator * (matrix a, matrix b)
{
    matrix c;
    forn(i, N) forn(j, N) forn(k, N) c.a[i][j] = (c.a[i][j] + a.a[i][k] * (ll)b.a[k][j]) % mod;
    return c;
}

const int NN = 1 << 16;

matrix t[2 * NN];

inline matrix get(int l, int r)
{
    l += NN;
    r += NN;
    matrix resl(1), resr(1);
    while (l <= r)
    {
        if ((l & 1) == 1) resl = resl * t[l];
        if ((r & 1) == 0) resr = t[r] * resr;
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return resl * resr;
}
inline matrix mpow(matrix a, ll b)
{
    matrix res(1);
    while (b)
    {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


const int maxn = (int)2e5 + 10;

int a[maxn];

pair<ll, int> e[maxn];
map<ll, int> M;

ll y[maxn * 2];
int yc = 0;

matrix ooops[maxn];

int n;
inline int getVal(ll x)
{
    if (M.find(x) != M.end()) return M[x];
    return a[x % n];
}


void Do(matrix &res, ll l, ll r)
{
    if (l > r) return;
    ll bl = l / n;
    ll br = r / n;
    if (bl == br)
    {
        res = res * get(l % n, r % n);
    }
    else
    {
        res = res * get(l % n, n - 1);
        res = res * mpow(get(0, n - 1), (br - bl - 1));
        res = res * get(0, r % n);
    }
}

int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    ll k;
    scanf("%I64d%d", &k, &mod);
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    
    a[n] = a[0];
    forn(i, n)
    {
        t[i + NN].a[1][0] = 1;
        t[i + NN].a[0][1] = a[i];
        t[i + NN].a[1][1] = a[i + 1];
    }
    for (int i = NN - 1; i > 0; --i) t[i] = t[2 * i] * t[2 * i + 1];
    
    int m;
    scanf("%d", &m);
    forn(i, m) scanf("%I64d%d", &e[i].fs, &e[i].sc);
    forn(i, m) M[e[i].fs] = e[i].sc;
    forn(i, m) y[yc++] = e[i].fs - 1, y[yc++]= e[i].fs;

    sort(y, y + yc);
    yc = unique(y, y + yc) - y;

    forn(i, yc)
    {
        ooops[i].a[1][0] = 1;
        ooops[i].a[0][1] = getVal(y[i]);
        ooops[i].a[1][1] = getVal(y[i] + 1);
    }



    matrix res(1);
    ll x = -1;

    forn(i, yc)
    {
        if (y[i] > k - 1) break;
        Do(res, x + 1, y[i] - 1);
        res = res * ooops[i];
        x = y[i];
    } 
    Do(res, x + 1, k - 1);
    
    printf("%d\n", res.a[1][0] % mod); 

    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}