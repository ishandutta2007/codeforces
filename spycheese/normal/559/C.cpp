#include <bits/stdc++.h>

#ifndef LOCAL
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
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 2015;
const int H = 400179;
int h, w, n;
ipair b[N];
int d[N];
ll fact[H], rfact[H];

ll powm(ll a, ll b)
{
    ll aa = a, r = 1;
    while (b)
    {
        if (b&1)
            (r *= aa) %= MOD;
        (aa *= aa) %= MOD;
        b >>= 1;
    }
    return r;
}

ll cnk(int c, int k)
{
    return ((fact[c]*rfact[k])%MOD*rfact[c-k])%MOD;
}

int main()
{
    ios::sync_with_stdio(false);

    fact[0] = 1;
    for (int i = 1; i < H; ++i)
        fact[i] = (fact[i-1] * i) % MOD;
    for (int i = 0; i < H; ++i)
        rfact[i] = powm(fact[i], MOD-2);

    cin >> h >> w >> n;
    if (h == 1 || w == 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i].first >> b[i].second;
        --b[i].first;
        --b[i].second;
    }
    b[n+1] = mp(h-1, w-1);
    n += 2;
    sort(b, b+n);

    d[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        int x = b[i].first, y = b[i].second;
        d[i] = cnk(b[i].first+b[i].second, b[i].first);
        for (int j = 1; j < i; ++j)
        {
            int nx = b[j].first, ny = b[j].second;
            if (nx > x || ny > y)
                continue;
            d[i] -= (d[j] * cnk((x-nx)+(y-ny), y-ny)) % MOD - MOD;
            d[i] %= MOD;
        }
    }
    cout << d[n-1] << "\n";
    
    return 0;
}