#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 10;

int N;
int board[MAXN][MAXN];

struct loc
{
    int x, y;
    int cg;
    int ct;

    loc ()
    {
        x = 0;
        y = 0;
        cg = 0;
        ct = 0;
    }

    loc (const loc &r)
    {
        x = r.x;
        y = r.y;
        cg = r.cg;
        ct = r.ct;
    }
};

inline bool operator < (loc left, loc right)
{
    if (left.cg != right.cg)
        return left.cg < right.cg;
    if (left.x != right.x)
        return left.x < right.x;
    if (left.y != right.y)
        return left.y < right.y;
    if (left.ct != right.ct)
        return left.ct < right.ct;
    return false;
}

map <loc, pair <int, int> > mm;
pair <int, int> nb;

int xc[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
int yc[8] = {-1, -1, -2, -2, 1, 1, 2, 2};

vector <pair <loc, pair <int, int> > > q;

void run (loc cloc, pair <int, int> cres)
{
    if (cloc.x < 0 || cloc.x >= N || cloc.y < 0 || cloc.y >= N) return;
    if (board[cloc.x][cloc.y] == cloc.cg + 1)
        cloc.cg++;

    if (cres.first > 2 * N * N) return;

    if (cloc.cg == N * N)
    {
        nb = min (nb, cres);
        return;
    }

    if (mm.find(cloc) == mm.end())
        mm[cloc] = cres;
    else
    {
        if (mm[cloc] <= cres)
            return;
        mm[cloc] = cres;
    }

    int cf = cres.first, cs = cres.second;
    if (cloc.ct == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            loc nloc(cloc);
            nloc.x += xc[i];
            nloc.y += yc[i];
            q.push_back(make_pair(nloc, make_pair (cf + 1, cs)));
        }
    }
    else if (cloc.ct == 1)
    {
        for (int i = -10; i <= 10; i++)
        {
            loc nloc(cloc);
            nloc.x += i;
            q.push_back(make_pair(nloc, make_pair (cf + 1, cs)));
        }
        for (int i = -10; i <= 10; i++)
        {
            loc nloc(cloc);
            nloc.y += i;
            q.push_back(make_pair(nloc, make_pair (cf + 1, cs)));
        }
    }
    else
    {
        for (int i = -10; i <= 10; i++)
        {
            loc nloc(cloc);
            nloc.x += i;
            nloc.y += i;
            q.push_back(make_pair(nloc, make_pair (cf + 1, cs)));
        }
        for (int i = -10; i <= 10; i++)
        {
            loc nloc(cloc);
            nloc.x -= i;
            nloc.y += i;
            q.push_back(make_pair(nloc, make_pair (cf + 1, cs)));
        }
    }

    for (int i = 0; i < 3; i++)
    {
        loc nloc(cloc);
        nloc.ct = i;
        q.push_back(make_pair(nloc, make_pair(cf + 1, cs + 1)));
    }
}

void gogo()
{
    for (int i = 0; i < q.size(); i++)
    {
        run (q[i].first, q[i].second);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    nb = make_pair (1e9, 1e9);
    loc cloc;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 1)
            {
                cloc.x = i;
                cloc.y = j;
                cloc.cg = 1;
            }
    for (int i = 0; i < 3; i++)
    {
        cloc.ct = i;
        q.push_back (make_pair(cloc, make_pair (0, 0)));
    }
    gogo();
    cout << nb.first << " " << nb.second << "\n";
}