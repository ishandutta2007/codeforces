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

const int MAXN = 5117, MAXK = 21;

int n, k, qs, arr[MAXN], a, ans;
set<pair<int, int> > q[MAXK];

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d", &n, &k);
    q[0].insert(mp(0, 0));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        for (int j = 1; j <= k; j++)
            for (int t = j; t <= k; t++)
            {
                auto it = q[t].lower_bound(mp(arr[i] * j, -1));
                if (it == q[t].end() || it->first != arr[i] * j)
                    q[t].insert(mp(arr[i] * j, j));
                else if (it->second > j)
                {
                    q[t].erase(it);
                    q[t].insert(mp(arr[i] * j, j));
                }
            }
    }

    scanf("%d", &qs);
    for (int qqs = 0; qqs < qs; qqs++)
    {
        scanf("%d", &a);
        ans = INF;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k && arr[i] * j <= a; j++)
            {
                auto it = q[k - j].lower_bound(mp(a - arr[i] * j, -1));
                if (it != q[k - j].end() && it->first == a - arr[i] * j)
                    ans = min(ans, j + it->second);
            }

        printf("%d\n", ans == INF ? -1 : ans);
    }

    return 0;
}