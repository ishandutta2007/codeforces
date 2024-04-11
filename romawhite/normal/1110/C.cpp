#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, b, a) for (int i = (b)-1; i >= (a); --i)
#define FILL(A, value) memset(A, value, sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int MOD = 998244353;
const double Pi = acos(-1.);

const int MAX = 2002000;

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int R[25] = {0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
int main()
{
    int q;
    cin >> q;
    FOR(i, 0, q)
    {
        int a;
        cin >> a;

        if ((a & (a + 1)) != 0)
        {
            int res = 1;
            while (res < a)
                res = 2 * res + 1;
            cout << res << endl;
        }
        else
        {
            int id = 0;
            int val = 1;
            while (val < a)
            {
                ++id;
                val = 2 * val + 1;
            }
            cout << R[id] << endl;
        }
    }
    return 0;
}