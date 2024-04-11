#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int t;
string f[8];

bool read()
{
    forn (i, 8)
        cin >> f[i];
    return true;
}

bool used[8][8][2];
int dx[] = {2, -2, -2, 2};
int dy[] = {2, 2, -2, -2};

void dfs(pair<int, int> k, int a)
{
    used[k.first][k.second][a] = true;
    forn (i, 4)
    {
        int nx = k.first + dx[i];
        int ny = k.second + dy[i];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !used[nx][ny])
            dfs(mp(nx, ny), a);
    }
}

void solve()    
{
    vector<pair<int, int> > kon;
    forn (i, 8)
        forn (j, 8)
        {
            if (f[i][j] == 'K')
                kon.pb(mp(i, j));
        }
    if (kon[0].first % 4 != kon[1].first % 4 || kon[0].second % 4 != kon[1].second % 4)
    {
        cout << "NO" << endl;
        return;
    }
    dfs(kon[0], 0);
    dfs(kon[1], 1);
    forn (i, 8)
        forn (j, 8)
        if (used[i][j] && f[i][j] != '#')
        {
            cout << "YES" << endl;
            return;
        }
    cout << "NO" << endl;
}
    
int main()
{
#ifdef SU6
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    forn (i, t)
    {
        read();
        solve();
    }
    return 0;
}