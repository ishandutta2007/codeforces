/**
 *    author:  [itmo] enot.1.10
 *    created: 28.03.2016 19:46:31       
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

int a[5][N];
ll s[5][N];
int ac[5] = {0};
int n, b, c, k;
int f[N];

ll res = 1e18;

bool can(int x, ll v)
{
    int have = 0;
    forn(i, 5)
    {
        int j = i;
        int it = 0;
        while (j != x % 5)
        {
            j = (j + 1) % 5;
            ++it;
        }
        if (v < it * c) continue;
        ll down = (v - it * c) / b;
        int mn = max(0ll, x - it - down * 5);
        int mx = x - it;
        if (mn > mx) continue;
        int pos1 = lower_bound(a[i], a[i] + ac[i], mn) - a[i];
        int pos2 = lower_bound(a[i], a[i] + ac[i], mx + 1) - a[i];
        have += pos2 - pos1;
    }
    return have >= k;
}

void Do(int x, ll v)
{
    //eprintf("x = %d, v = %I64d\n", x, v);
    --v;
    ll val = 0;
    int cnt = 0;
    forn(i, 5)
    {
        int j = i;
        int it = 0;
        while (j != x % 5)
        {
            j = (j + 1) % 5;
            ++it;
        }
        if (v < it * c) continue;
        ll down = (v - it * c) / b;
        int mn = max(0ll, x - it - down * 5);
        int mx = x - it;
        if (mn > mx) continue;
        int pos1 = lower_bound(a[i], a[i] + ac[i], mn) - a[i];
        int pos2 = lower_bound(a[i], a[i] + ac[i], mx + 1) - a[i];
        //eprintf("pos1 = %d, pos2 = %d  sum1 = %I64d\n", pos1, pos2, (pos2 - pos1) * (ll)mx - (s[i][pos2] - s[i][pos1]));
        val += ((pos2 - pos1) * (ll)mx - (s[i][pos2] - s[i][pos1])) / 5 * b + (pos2 - pos1) * it * (ll)c;
        cnt += pos2 - pos1;
    }
    ++v;
    val += v * (k - cnt);
    //eprintf("--> %I64d (%I64d * %d)\n", val, v, k - cnt);
    res = min(res, val);
}


        
int t[5][N];
int tc[5] = {0};

int mnVal;

void test(int x)
{
    if (x < mnVal) return;
    t[x % 5][tc[x % 5]++] = x;
}

ll cost(int x, int y)
{
    int ost = (y - x + 5) % 5;
    assert(x + ost <= y);
    int d = (y - ost - x) / 5;
    return d * (ll)b + ost * (ll)c;
}

void testAll()
{
    forn(i, 5)
    {
        sort(t[i], t[i] + tc[i]);
        int st[5] = {0};
        int en[5] = {0};
        forn(z, tc[i])
        {
            int goal = t[i][z];
            forn(j, 5) while (en[j] < ac[j] && a[j][en[j]] <= goal) en[j]++;

            int sum = 0;
            forn(j, 5) sum += en[j] - st[j];

//            eprintf("goal = %d, sum = %d\n", goal, sum);
            assert(sum >= k);

            while (sum > k)
            {
                ll mn = -1e18;
                forn(j, 5) if (st[j] < en[j]) mn = max(mn, cost(a[j][st[j]], goal));
                forn(j, 5) if (st[j] < en[j] && mn == cost(a[j][st[j]], goal))
                {
                    st[j]++;
                    sum--;
                    break;
                }
            }
            assert(sum == k);

            ll val = 0;
            forn(j, 5)
            {
                int ost = (goal + 5 - j) % 5;
                int cnt = en[j] - st[j];
                if (!cnt) continue;
  //              eprintf("j = %d, st = %d, en = %d\n", j, st[j], en[j]);
                ll ss = s[j][en[j]] - s[j][st[j]];
                val += (cnt * (ll)(goal - ost) - ss) / 5 * (ll)b + cnt * (ll)c * ost;
            }
            res = min(res, val);
        }
    }
}




int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    scanf("%d%d%d%d", &n, &k, &b, &c);
    if (b >= c * 5)
    {
        b = c * 5;
    }
    forn(i, n)
    {
        int x;
        scanf("%d", &x);
        x += 1e9;
        a[x % 5][ac[x % 5]++] = x;
        f[i] = x;
    }
    sort(f, f + n);
    mnVal = f[k - 1];
    forn(i, 5) sort(a[i], a[i] + ac[i]);
    forn(i, 5) forn(j, ac[i]) s[i][j + 1] = s[i][j] + a[i][j];
    forn(i, n)
    {
        forn(j, 5) test(f[i] + j);
    }
    testAll();
    printf("%I64d\n", res);
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}