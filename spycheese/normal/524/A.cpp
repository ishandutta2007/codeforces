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

const int MAXN = 117;

int n, arr[MAXN * 2], m, k, a, b;
vector<int> ans;
set<pair<int, int> > q;

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        arr[n++] = a;
        arr[n++] = b;
        q.insert(mp(a, b));
        q.insert(mp(b, a));
    }
    sort(arr, arr + n);
    n = unique(arr, arr + n) - arr;

    for (int i = 0; i < n; i++)
    {
        ans.clear();
        for (int j = 0; j < n; j++)
        {
            if (i == j || q.count(mp(arr[i], arr[j])))
                continue;
            int cnt1 = 0, cnt2 = 0;
            for (int t = 0; t < n; t++)
            {
                if (t == i || t == j)
                    continue;
                if (q.count(mp(arr[i], arr[t])))
                {
                    cnt1++;
                    if (q.count(mp(arr[j], arr[t])))
                        cnt2++;
                }
            }

            if (100LL * cnt2 >= 1LL * k * cnt1)
                ans.pb(arr[j]);
        }
        printf("%d: %d", arr[i], sz(ans));
        for (auto f : ans)
            printf(" %d", f);
        putchar('\n');
    }

    return 0;
}