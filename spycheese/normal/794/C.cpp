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

const int N = 100179;

string s1, s2;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    n = sz(s1);
    sort(s1.begin(), s1.end(), std::greater<char>());
    sort(s2.begin(), s2.end());
    int k = (n % 2 == 0 ? n / 2 : n / 2 + 1);
    s1 = s1.substr(n - k, k);
    s2 = s2.substr(k, n - k);
    int s1i = 0, s2i = 0;

    string ans(n, '.');
    int i1 = 0, i2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            if (s1.back() < s2.back())
            {
                ans[i1++] = s1.back();
                s1.pop_back();
            } else {
                ans[n - ++i2] = s1[s1i++];
            }
        } else {
            if (s2.back() > s1.back())
            {
                ans[i1++] = s2.back();
                s2.pop_back();
            } else {
                ans[n - ++i2] = s2[s2i++];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}