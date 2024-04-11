#include <cstdio>

#include <vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long li;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

vector< pair<int, int> > g[500];
int Time = 1;
int u[500];
int l, r;

void dfs(int v)
{
    u[v] = Time;
    forn (i, g[v].size())
        if((g[v][i].second < l || g[v][i].second > r) && u[g[v][i].first] != Time)
            dfs(g[v][i].first);
}

int main()
{
     int n, m;
    scanf("%d%d", &n, &m);
    forn (i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].pb(mp(b, i));
        g[b].pb(mp(a, i));
    }
    
    int k;
    scanf("%d", &k);
    forn (i, k)
    {
        int ans = 0;
        scanf("%d%d", &l, &r);
        l--, r--;
        forn (i, n)
        {
            if(u[i] != Time)
            {
                dfs(i);
                ans++;
            }
        }
        printf("%d\n", ans);
        Time++;
    }

    return 0;
}