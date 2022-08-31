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

int n, ans;
string s, reposted, t;
map<string, int> q;

void tolower(string &str)
{
    for (int i = 0; i < sz(str); i++)
        str[i] = tolower(str[i]);
}

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    q["polycarp"] = 1;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> reposted >> t;

        tolower(s);
        tolower(t);
        q[s] = q[t] + 1;
    }

    for (auto p : q)
        ans = max(ans, p.second);

    printf("%d\n", ans);

    return 0;
}