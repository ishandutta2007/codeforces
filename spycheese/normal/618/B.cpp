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

const int N = 55;

int n, a[N][N];

void check(int * b)
{
    bool was[N];
    memset(was, 0, sizeof(was));
    for (int i = 0; i < n; ++i)
    {
        if (was[b[i]])
            return;
        was[b[i]] = true;
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i][j] != min(b[i], b[j]))
                return;
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << "\n";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i)
    {
        a[i][i] = n;
        check(a[i]);
        a[i][i] = 0;
    }


    return 0;
}