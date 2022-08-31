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
const ld DINF = numeric_limits<ld>::infinity();
const ll MOD = 1000000007;
const ld EPS = 1e-10;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 179;

ld a, b, c, d;

bool ok(ld x)
{
    ld minAD = min(min((a-x)*(d-x), (a-x)*(d+x)), min((a+x)*(d-x), (a+x)*(d+x)));
    ld maxAD = max(max((a-x)*(d-x), (a-x)*(d+x)), max((a+x)*(d-x), (a+x)*(d+x)));
    ld minBC = min(min((b-x)*(c-x), (b-x)*(c+x)), min((b+x)*(c-x), (b+x)*(c+x)));
    ld maxBC = max(max((b-x)*(c-x), (b-x)*(c+x)), max((b+x)*(c-x), (b+x)*(c+x)));
    if (minAD > maxBC || minBC > maxAD)
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> a >> b >> c >> d;
    ld l = 0.0, r = max(max(abs(a), abs(b)), max(abs(c), abs(d))) * 2.0;
    for (int step = 0; step < N; ++step)
    {
        ld m = (l + r) * 0.5;
        if (ok(m))
            r = m;
        else
            l = m;
    }

    cout.precision(25);
    cout << l << "\n";

    return 0;
}