#include <bits/stdc++.h>

#ifndef LOCAL
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
const int DX[] = { 1,  0, -1,  0};
const int DY[] = { 0,  1,  0, -1};

// ========================================================================= //

const int N = 1011;

int n, m;
string s[N];
int ans[N][N];

int dfs(int x, int y)
{
    static bool vis[N][N];
    if (vis[x][y])
        return 0;
    if (s[x][y] == '*')
        return 1;
    vis[x][y] = true;
    int r = 0;
    for (int i = 0; i < 4; ++i)
        r += dfs(x+DX[i], y+DY[i]);
    return r;
}
void dfs2(int x, int y, int z)
{
    static bool vis[N][N];
    if (vis[x][y])
        return;
    if (s[x][y] == '*')
        return;
    vis[x][y] = true;
    ans[x][y] = z;
    for (int i = 0; i < 4; ++i)
        dfs2(x+DX[i], y+DY[i], z);
}

int main()
{
    ios::sync_with_stdio(false);

    int q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dfs2(i, j, dfs(i, j));
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cout << ans[x][y] << "\n";
    }


    return 0;
}