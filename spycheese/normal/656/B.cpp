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

const int N = 100;

int n;
ll a[N], b[N];

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    ll x = 1;
    for (int i = 2; i <= 16; ++i)
        x = x*i/gcd(x, i);
    ll k = 0;
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < n; ++j)
            if (i % a[j] == b[j])
            {
                ++k;
                break;
            }
    }
    cout.precision(10);
    cout << 1.*k/x << "\n";

    return 0;
}