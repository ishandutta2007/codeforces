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

multiset < ll > a;

bool check(int cnt)
{
    multiset < ll > s = a;
    vector < ll > kk;
    for (int i = 0; i < cnt; ++i)
    {
        ll k = 1;
        while (true)
        {
            auto it = s.find(k);
            if (it == s.end())
                break;
            s.erase(it);
            k *= 2;
        }
        if (k == 1)
            return false;
        kk.push_back(k / 2);
    }
    for (ll k : kk)
    {
        if (s.empty())
            return true;
        auto it = s.end();
        --it;
        if (*it > k * 2)
            return false;
        s.erase(it);
    }
    return s.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    int maxA = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        scanf("%I64d", &x);
        a.insert(x);
        if (x == 1)
            ++maxA;
    }

    int l = 0, r = maxA + 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (r > maxA)
        cout << "-1\n";
    else
    {
        for (int i = r; i <= maxA; ++i)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}