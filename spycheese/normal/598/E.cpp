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

const int N = 33;
const int K = 55;

int d[N][N][K];

int main()
{
    ios::sync_with_stdio(false);

    memset(d, 0x3f, sizeof(d));
    for (int n = 0; n <= 30; ++n)
        for (int m = 0; m <= 30; ++m)
            for (int k = 0; k <= min(n*m, 50); ++k)
            {
                if (k == 0 || k == n*m)
                    d[n][m][k] = 0;
                else
                {
                    for (int x = 1; x*2 <= n; ++x)
                        for (int y = 0; y <= k; ++y)
                            d[n][m][k] = min(d[n][m][k], d[x][m][y] + d[n-x][m][k-y] + m*m);
                    for (int x = 1; x*2 <= m; ++x)
                        for (int y = 0; y <= k; ++y)
                            d[n][m][k] = min(d[n][m][k], d[n][x][y] + d[n][m-x][k-y] + n*n);
                }
            }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int n, m, k;
        cin >> n >> m >> k;
        cout << d[n][m][k] << "\n";
    }

    return 0;
}