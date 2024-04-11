#include <bits/stdc++.h>

#ifndef LOCAL
#define stderr lorem_ipsum
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;

// ========================================================================= //

const int N = 239;

int n, f[N];

bool isIdpt(int * f)
{
    for (int i = 0; i < n; ++i)
        if (f[i] != f[f[i]])
            return false;
    return true;
}

void f1f2(int * f1, int * f2, int * g)
{
    for (int i = 0; i < n; ++i)
        g[i] = f1[f2[i]];
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    static int vis[N];
    int cct = 1;
    ll ans = -1;
    for (int i = 0; i < n; ++i)
        if (!vis[i])
        {
            int cv = i;
            int cbeg = cct;
            ll cans = -1;
            while (true)
            {
                vis[cv] = cct++;
                if (vis[f[cv]] != 0)
                {
                    if (vis[f[cv]] >= cbeg)
                        cans = vis[cv] - vis[f[cv]] + 1;
                    break;
                }
                cv = f[cv];
            }
            if (cans != -1)
            {
                if (ans == -1)
                    ans = cans;
                else
                    ans = ans*cans / gcd(ans, cans);
            }
        }
    ll ians = ans;
    while (ians <= n*2)
        ians += ans;
    cout << ians << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i];
        --f[i];
    }
    static int cf[N];
    memcpy(cf, f, sizeof(cf));
    for (int ans = 1; ans <= n*2; ++ans)
    {
        if (isIdpt(cf))
        {
            cout << ans << "\n";
            return 0;
        }
        static int ncf[N];
        f1f2(f, cf, ncf);
        memcpy(cf, ncf, sizeof(cf));
    }

    solve();

    return 0;
}