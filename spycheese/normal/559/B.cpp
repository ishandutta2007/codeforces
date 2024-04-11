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

string s1, s2;
bool eq(int p1, int p2, int l)
{
    if (l & 1)
    {
        for (int i = 0; i < l; ++i)
            if (s1[p1+i] != s2[p2+i])
                return false;
        return true;
    }
    int nl = l >> 1;
    return (eq(p1, p2, nl) && eq(p1+nl, p2+nl, nl)) || (eq(p1, p2+nl, nl) && eq(p1+nl, p2, nl));
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    if (eq(0, 0, sz(s1)))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}