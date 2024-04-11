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

int n;
ipair a[N];
int add[N];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    
    for (int i = 0; i < n; ++i)
    {
        int x1 = i, x2 = a[i].second;
        if (x1 > x2)
            swap(x1, x2);
        ++add[x1];
        --add[x2];
    }
    int cnt = 1, cx = 0;
    for (int i = 0; i < n - 1; ++i)
        cnt += !(cx += add[i]);
    cout << cnt << "\n";

    return 0;
}