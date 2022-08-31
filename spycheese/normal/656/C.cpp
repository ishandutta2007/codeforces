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

const int N = 100179;

ll ali(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    ll ans = 0;
    for (char c : s)
        ans += (ll('@'<c && '['>c)*ali(c)) - (ll('`'<c && '{'>c)*ali(c));
    cout << ans << "\n";

    return 0;
}