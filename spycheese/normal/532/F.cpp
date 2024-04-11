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

const int MAXN = 200117, ALP = 26;

int n, m, p[MAXN * 2];
char s[MAXN], t[MAXN]; int ps[MAXN * 2]; int g[ALP][MAXN];
vector<int> ans;
bool h[ALP];

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d\n", &n, &m);
    scanf("%s", s);
    scanf("%s", t);

    for (int i = 0; i < m; i++)
        h[t[i] - 'a'] = true;

    memset(g, -1, sizeof(g));
    for (int j = 0; j < ALP; j++)
    {
        if (!h[j])
            continue;
        for (int k = 0; k < ALP; k++)
        {
            ps[0] = (t[0] == 'a' + j);
            for (int i = 1; i <= m + n; i++)
            {
                ps[i] = (i == m ? -1 : (i < m ? (t[i] == 'a' + j) : (s[i - m - 1] == 'a' + k)));
                for (p[i] = p[i - 1]; p[i] && ps[p[i]] != ps[i]; p[i] = p[p[i] - 1]);
                if (ps[p[i]] == ps[i])
                    p[i]++;
                if (p[i] == m)
                    g[j][i - 2 * m] = k;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool f = true;
        for (int j = 0; j < ALP && f; j++)
            if (h[j])
                f =  f &&((g[j][i] != -1) && ((j == g[g[j][i]][i]) || (-1 == g[g[j][i]][i])));
        if (f)
            ans.pb(i + 1);
    }

    printf("%d\n", sz(ans));
    for (auto i : ans)
        printf("%d ", i);
    putchar('\n');

    return 0;
}