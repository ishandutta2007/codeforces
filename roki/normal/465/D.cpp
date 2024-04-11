#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef double ld;
typedef pair<int,int> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second

int c[8][3];

bool read() {
    forn (i, 8)
        forn (j, 3)
        cin >> c[i][j];
    return true;
}

ld dist[100];
int t[8];
int p[6][3];

ld getDist(int i, int j)
{
    ld dx = c[i][p[t[i]][0]] - c[j][p[t[j]][0]];
    ld dy = c[i][p[t[i]][1]] - c[j][p[t[j]][1]];
    ld dz = c[i][p[t[i]][2]] - c[j][p[t[j]][2]];
    return (dx * dx + dy * dy + dz * dz);
}

ld dif[] = {1, (2.0), (3.0)};

ld cdist[8][8];

bool check()
{
    int sz = 0;
    forn (i, 8)
        forn (j, i)
            dist[sz++] = cdist[i][j];
    
    sort(dist, dist + sz);
    if (dist[0] < 1e-8)
        return false;

    if (fabs(dist[11] / dist[0] - dif[0]) > 1e-8)
        return false;
    if (fabs(dist[23] / dist[0] - dif[1]) > 1e-8)
        return false;
    if (fabs(dist[12] / dist[0] - dif[1]) > 1e-8)
        return false;
    if (fabs(dist[24] / dist[0] - dif[2]) > 1e-8)
        return false;
    if (fabs(dist[27] / dist[0] - dif[2]) > 1e-8)
        return false;

    return true;
}

bool inc()
{
    int r = 7;
    while(r >= 0 && ++t[r] == 6)
    {
        t[r] = 0;
        r--;
    }
    if (r == -1)
        return false;
    for (int i = r; i < 8; ++i)
        forn (j, i)
            cdist[i][j] = getDist(i, j);
    return true;
}

void rec()
{
    forn (i, 8)
        forn (j, i)
            cdist[i][j] = getDist(i, j);

    while(inc())
    {
        if (check())
        {
            cout << "YES" << endl;
            forn (i, 8)
            {
                forn (j, 3)
                    cout << c[i][p[t[i]][j]] << ' ';
                cout << endl;
            }
            exit(0);
        }
    }
}

void solve() {
    vector<int> v;
    forn (i, 3)
        v.pb(i);

    int csz = 0;

    do
    {
        forn (j, 3)
            p[csz][j] = v[j];
        csz++;
    }while(next_permutation(all(v)));

    rec();

    cout << "NO" << endl;
}


int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    read();
    solve();

    return 0;
}