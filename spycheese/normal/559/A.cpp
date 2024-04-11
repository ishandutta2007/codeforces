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
const ld EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 100179;
const ld PI = acos((ld)(-1.0));
const ld S120 = sin(PI*2.0/3.0);

int main()
{
    ios::sync_with_stdio(false);

    ld a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    ld ans = 0.0;
    ans += 0.5*a1*a6*S120;
    ans += 0.5*a3*a4*S120;
    ld h = (a1+a6)*S120;
    ans += 0.5*h*(a2+a5);
    ans /= sqrt(3.0)*0.25;
    cout << (ll)round(ans) << "\n";

    return 0;
}