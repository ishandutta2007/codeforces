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

const int MAXN = 20117;

int n, m, t, a, b, c, arr[MAXN], cur, op[MAXN], ans[MAXN], r;
pair<int, int> e[MAXN * 2];
bool has_solution;

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    has_solution = false;
    scanf("%d %d %d", &n, &m, &t);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d", &a, &b, &c);
        arr[i] = a * 60 * 60 + b * 60 + c;
        e[i * 2] = mp(arr[i], i);
        e[i * 2 + 1] = mp(arr[i] + t, -1 - i);
    }
    sort(e, e + 2 * n);

    for (int ll = 0, i = -1, rr; ll < 2 * n; )
    {
        for (rr = ll + 1; rr < 2 * n && e[rr].first == e[rr - 1].first; rr++);
        for (; ll < rr && e[ll].second < 0; ll++)
            if (op[ans[-e[ll].second - 1]] == e[ll].first - t)
            {
                op[ans[-e[ll].second - 1]] = -INF;
                cur--;
            }
        for (; ll < rr; i++, ll++)
        {
            cur++;
            if (cur == m + 1)
            {
                cur--;
                ans[i + 1] = ans[i];
            }
            else
                ans[i + 1] = ++r;
            op[ans[i + 1]] = e[ll].first;
            if (cur == m)
                has_solution = true;
        }
    }

    if (!has_solution)
    {
        printf("No solution\n");
        return 0;
    }

    printf("%d\n", r);
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);

    return 0;
}