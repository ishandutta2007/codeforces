#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int) (a).size())
const double PI = acos(-1.0);

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

const int MAXN = 200117;

int n, a[MAXN], b[MAXN], b1, b2, sa;

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d", &n);
    b1 = -INF;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);

        sa += a[i];
        if (b[i] > b1)
        {
            b2 = b1;
            b1 = b[i];
        }
        else if (b[i] > b2)
            b2 = b[i];
    }

    for (int i = 0; i < n; i++)
        printf("%d ", (sa - a[i]) * (b[i] == b1 ? b2 : b1));
    putchar('\n');

    return 0;
}