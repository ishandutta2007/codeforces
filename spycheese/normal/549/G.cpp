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
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 200179;

int n;
ll a[N];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] += i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        if (a[i] - i < 0 || (i != 0 && a[i]-i < a[i - 1]-(i-1)))
        {
            cout << ":(\n";
            return 0;
        }
    for (int i = 0; i < n; ++i)
        cout << a[i] - i << " ";

    return 0;
}