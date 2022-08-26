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

// ========================================================================= //

const int N = 2179;

int n, t;
int w[N], q[N];

vector < int > pw[N];

int d[N][N];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> t;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i] >> q[i];
        pw[w[i]].push_back(q[i]);
    }

    for (int i = 0; i < N; ++i)
        sort(pw[i].begin(), pw[i].end(), greater < int >());

    for (int i = t; i >= 0; --i)
        for (int j = 0; j < N; ++j)
        {
            int mcu = (t - i < 20 ? 1 << (t-i) : IINF);
            if (j > mcu)
            {
                d[i][j] = -IINF;
                continue;
            }
            int cu = j;
            int cs = 0;
            d[i][j] = d[i + 1][(j + 1) / 2];
            for (int e : pw[i])
            {
                cs += e;
                ++cu;
                if (cu > mcu)
                    break;
                d[i][j] = max(d[i][j], cs + d[i + 1][(cu + 1) / 2]);
            }
        }

    cout << d[0][0] << "\n";

    return 0;
}