#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m;
char c[500][500];

bool read()
{
    if(!(cin >> n >> m))
        return false;
    forn (i, n)
        forn (j, m)
        cin >> c[i][j];
    return true;
}

struct step
{
    char c;
    int x, y;
};

bool used[500][500];
vector<step> ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, bool ft = true)
{
    used[x][y] = true;
    step cur;
    cur.c = 'B';
    cur.x = x + 1, cur.y = y + 1;
    ans.pb(cur);
    forn (i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if(!used[nx][ny] && c[nx][ny] != '#')
                dfs(nx, ny, false);
        }
    }
    if(!ft)
    {
        cur.c = 'D';
        ans.pb(cur);
        cur.c = 'R';
        ans.pb(cur);
    }
}

void solve()
{
    forn (i, n)
        forn (j, m)
        if(!used[i][j] && c[i][j] != '#')
            dfs(i, j);
    cout << ans.size() << endl;
    forn (i, ans.size())
        printf("%c %d %d\n", ans[i].c, ans[i].x, ans[i].y);
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}