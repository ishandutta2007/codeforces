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

const int N = 1500179;

int n, q;
int d0 = 0, d1 = 1;

int main()
{
    ios::sync_with_stdio(false);
    
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x;
            scanf("%d", &x);
            if (x % 2 != 0)
            {
                --x;
                int nd1 = d0;
                int nd0 = (d1 - 2 + n) % n;
                d0 = nd0;
                d1 = nd1;
            }
            d0 = (d0 - x + n*2) % n;
            d1 = (d1 - x + n*2) % n;
        } else
            swap(d0, d1);
    }

    static int ans[N];
    for (int i = 0; i < n; i += 2)
        ans[i] = (d0 + i) % n;
    for (int i = 1; i < n; i += 2)
        ans[i] = (d1 + i - 1) % n;
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i] + 1);

    return 0;
}