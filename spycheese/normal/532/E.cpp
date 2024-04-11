#include <bits/stdc++.h>

#ifndef LOCAL
#define stderr lorem_ipsum
#define cerr dolor_sit_amet
#endif

#define sz(x) ((int)((x).size()))
#define mp(x,y) make_pair((x), (y))
#define allIter(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits < double > ::infinity();
const double EPS = 1e-9;
const int DX[] = {1, 0, -1,  0, 1, -1,  1, -1};
const int DY[] = {0, 1,  0, -1, 1, -1, -1,  1};

const int N = 100179;
const ll P = 257;
const ll MOD = 1000000009;

int n;
string s, t;

ll ppow[N], hs[N], ht[N];
unordered_set < int > ans;
int spos;
char sc;

inline ll getPrefHashS(int x)
{
    if (x <= spos)
        return hs[x];
    return ((((hs[spos] * P) % MOD + sc) * ppow[x - spos - 1]) % MOD + (MOD + hs[x - 1] - (hs[spos] * ppow[x - spos - 1]) % MOD)) % MOD;
}

inline ll getHashS(int pos, int len)
{
    return (MOD + getPrefHashS(pos + len) - (getPrefHashS(pos) * ppow[len]) % MOD) % MOD;
}

inline ll getHashT(int pos, int len)
{
    return (MOD + ht[pos + len] - (ht[pos] * ppow[len]) % MOD) % MOD;
}

int lcp(int l, int r)
{
    while (l < r)
    {
        int m = (l + r + 1) >> 1;
        if (ht[m] == getPrefHashS(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int lcs(int l, int r)
{
    while (l < r)
    {
        int m = (l + r + 1) >> 1;
        if (getHashS(n+1-m, m) == getHashT(n-m, m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);

    ppow[0] = 1;
    for (int i = 1; i < N; ++i)
        ppow[i] = (ppow[i - 1] * P) % MOD;

    cin >> n >> s >> t;
    hs[0] = 0;
    for (int i = 0; i < n; ++i)
        hs[i + 1] = (hs[i] * P + s[i]) % MOD;
    ht[0] = 0;
    for (int i = 0; i < n; ++i)
        ht[i + 1] = (ht[i] * P + t[i]) % MOD;


    int slcp = 0;
    while (slcp < n && s[slcp] == t[slcp])
        ++slcp;
    int slcs = 0;
    while (slcs < n && s[n-1-slcs] == t[n-1-slcs])
        ++slcs;

    for (spos = slcp; spos <= n - slcs; ++spos)
    {
        for (sc = 'a'; sc <= 'z'; ++sc)
        {
            int a1, a2 = -1;
            if (slcp < spos)
                a1 = slcp;
            else if (spos != n && t[spos] == sc)
                a1 = lcp(slcp + 1, n);
            else
                a1 = slcp;
            if (slcs < n - spos)
                a2 = slcs;
            else if (spos != 0 && t[n - slcs - 1] == sc)
                a2 = lcs(slcs + 1, n);
            else
                a2 = slcs;
            if (a1 + a2 >= n)
                ans.insert(getPrefHashS(n + 1));
        }
    }
    cout << ans.size() << "\n";

    return 0;
}