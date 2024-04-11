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

const int N = 1179;

int n, m;
vector < int > e[N];
int col[N];
int mm;

void bfs(int s)
{
    int d[N];
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    vector < int > q;
    q.push_back(s);
    for (int i = 0; i < q.size(); ++i)
    {
        int v = q[i];
        mm = max(mm, d[v]);
        for (int nv : e[v])
            if (d[nv] > d[v] + 1)
            {
                d[nv] = d[v] + 1;
                q.push_back(nv);
            }
    }
}

void colDfs(int v, int c)
{
    if (col[v] != 0)
    {
        if (col[v] != c)
        {
            cout << "-1\n";
            exit(0);
        } else
            return;
    }
    col[v] = c;
    bfs(v);

    for (int nv : e[v])
        colDfs(nv, 3 - c);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (col[i] != 0)
            continue;
        mm = 0;
        colDfs(i, 1);
        ans += mm;
    }

    cout << ans << "\n";

    return 0;
}