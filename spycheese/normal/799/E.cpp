#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 200500;

class SSet
{
    multiset < int > s1, s2;
    ll sum = 0;
public:
    void insert(int x)
    {
        if (s2.empty() || (*s2.begin()) > x)
        { 
            s1.insert(x);
            sum += x;
        }
        else
            s2.insert(x);
    }

    void erase(int x)
    {
        auto it = s1.find(x);
        if (it != s1.end())
        {
            s1.erase(it);
            sum -= x;
        }
        else
            s2.erase(s2.find(x));
    }

    ll getSum(int m)
    {
        if (sz(s1) + sz(s2) < m || m < 0)
            return LINF;
        while (sz(s1) > m)
        {
            auto it = s1.end();
            --it;
            s2.insert(*it);
            sum -= *it;
            s1.erase(it);
        }
        while (sz(s1) < m)
        {
            auto it = s2.begin();
            s1.insert(*it);
            sum += *it;
            s2.erase(it);
        }
        return sum;
    }
} ss;

int n, m, k;
int costs[N];
bool good1[N], good2[N];
vector < int > c[2][2];
vector < ll > cs[2][2];

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &costs[i]);
    int gc;
    scanf("%d", &gc);
    for (int i = 0; i < gc; ++i)
    {
        int x;
        scanf("%d", &x);
        --x;
        good1[x] = 1;
    }
    scanf("%d", &gc);
    for (int i = 0; i < gc; ++i)
    {
        int x;
        scanf("%d", &x);
        --x;
        good2[x] = 1;
    }

    for (int i = 0; i < n; ++i)
        c[good1[i]][good2[i]].push_back(costs[i]);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            sort(c[i][j].begin(), c[i][j].end());
            cs[i][j].push_back(0);
            for (int x : c[i][j])
                cs[i][j].push_back(cs[i][j].back() + x);
        }

    for (int x : c[0][0])
        ss.insert(x);
    for (int i = k; i < sz(c[0][1]); ++i)
        ss.insert(c[0][1][i]);
    for (int i = k; i < sz(c[1][0]); ++i)
        ss.insert(c[1][0][i]);

    ll ans = LINF;
    for (int cnt11 = 0; cnt11 <= sz(c[1][1]); ++cnt11)
    {
        if (cnt11 >= k)
            ans = min(ans, cs[1][1][cnt11] + ss.getSum(m - cnt11));
        else if (k - cnt11 <= sz(c[1][0]) && k - cnt11 <= sz(c[0][1]))
            ans = min(ans, cs[1][1][cnt11] + cs[0][1][k - cnt11] + cs[1][0][k - cnt11] + ss.getSum(m - 2*k + cnt11));

        if (cnt11 != sz(c[1][1]))
        {
            if (k - cnt11 - 1 >= 0 && k - cnt11 - 1 < sz(c[0][1]))
                ss.insert(c[0][1][k - cnt11 - 1]);
            if (k - cnt11 - 1 >= 0 && k - cnt11 - 1 < sz(c[1][0]))
                ss.insert(c[1][0][k - cnt11 - 1]);
        }
    }

    if (ans >= LINF)
        ans = -1;
    cout << ans << "\n";

    return 0;
}