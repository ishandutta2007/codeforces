#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
struct _edge{
    int v;
    ll a, b;//nod, nok
};

int n, m;
vector<_edge> r[100];
ll b[100], t[100];
int ans[100];

ll nod (ll a, ll b)
{
    return (b == 0)?(a):(nod(b, a % b));
}

ll nok(ll a, ll b)
{
    ll w = nod(a, b);
    ll w1 = ((ll)a) / w * b;
    if (w1 > 1000000) return 1000001;
    return w1;
}

bool dfs(int v)
{
    FOR(i, r[v].size())
    {
        int wv = r[v][i].v;
        if (ans[wv] == -1)
        {
            ll w = r[v][i].b / ans[v] * r[v][i].a;

            if (t[wv] % w != 0 || w % b[wv] != 0)
                return false;
            ans[wv] = w;
            if (!dfs(wv))
            {
                return false;
            }
        }
        else
        {
            if (nok(ans[v], ans[wv])!=r[v][i].b || nod(ans[v], ans[wv]) != r[v][i].a) return false;
        }
    }
    return true;
}

void purify(int v)
{
    ans[v] = -1;
    FOR(i, r[v].size())
    {
        if (ans[r[v][i].v] == -1) continue;
        purify(r[v][i].v);
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
    scanf("%d%d", &n, &m);
    FOR(i, m)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--, b--;
        _edge w;
        w.v = b;
        w.a = c;
        w.b = d;
        r[a].push_back(w);
        w.v = a;
        r[b].push_back(w);
    }

    FOR(g, n)
        ans[g] = -1;
    FOR(i, n)
    {
        if (r[i].size() == 0)
        {
            ans[i] = 1;
            continue;
        }
        b[i] = r[i][0].a;
        for (int j = 1; j < r[i].size(); ++j)
        {
            ll w = nok(b[i], r[i][j].a);
            if (w > 1000000)
            {
                cout << "NO";
                return 0;
            }
            b[i] = w;
        }
        t[i] = r[i][0].b;
        for (int j = 1; j < r[i].size(); ++j)
        {
            t[i] = nod(t[i], r[i][j].b);
        }
    }
//  FOR(i, n)
//      cerr << ans[i] << '\n';
//  FOR(i, n)
//      cerr << b[i] << ' '<< t[i] << '\n';
    FOR(i, n)
    {
        if (ans[i] != -1) continue;
        for (int j = 1; j <= t[i]; ++j)
        {
            if (t[i] % j != 0) continue;
            if (j % b[i] != 0) continue;
            ans[i] = j;
            if (dfs(i)) break;
                else purify(i);
        }
        if (ans[i] == -1)
        {
            cout << "NO";
            return 0;
        }
    }
    printf("YES\n");
    FOR(i, n)
        printf("%d ", ans[i]);
    return 0;
}