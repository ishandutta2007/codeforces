#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int P = 1 << 18;
const int MAXP = 2 * P + 100;

int N, Q;
vector <int> edge[MAXN];
int nord;
int ord[MAXN];
int rord[MAXN];
int dep[MAXN];
int anc[MAXN][20];
int ssize[MAXN];

void flood (int cloc, int last)
{
    if (cloc != 0) dep[cloc] = 1 + dep[last];
    anc[cloc][0] = last;
    for (int i = 1; i < 20; i++)
        anc[cloc][i] = anc[anc[cloc][i-1]][i-1];

    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        flood (neigh, cloc);
        ssize[cloc] += ssize[neigh];
    }
    ssize[cloc]++;
}

void ford (int cloc, int last)
{
    ord[nord] = cloc;
    rord[cloc] = nord;
    nord++;

    /*vector <pair <int, int> > v;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        v.push_back(make_pair (ssize[neigh], neigh));
    }
    sort (v.begin(), v.end());
    reverse (v.begin(), v.end());*/

    for (auto x : edge[cloc])
    {
        if (x == last) continue;
        ford (x, cloc);
    }
}

int get_anc (int x, int cnt)
{
    for (int i = 0; i < 20; i++)
        if (cnt & (1 << i))
            x = anc[x][i];
    return x;
}

bool is_anc (int x, int y)
{
    int g = get_anc (y, dep[y] - dep[x]);
    return (g == x);
}

set <pair <int, int> > s;

int smax[MAXP], scnt[MAXP];
int nprop[MAXP];

void prop (int cloc)
{
    smax[2*cloc] += nprop[cloc];
    smax[2*cloc+1] += nprop[cloc];
    nprop[2*cloc] += nprop[cloc];
    nprop[2*cloc+1] += nprop[cloc];
    nprop[cloc] = 0;
}

void sfill (int cloc, int lo, int hi)
{
    nprop[cloc] = 0;
    if (lo >= N)
    {
        smax[cloc] = -1e8;
        scnt[cloc] = hi - lo + 1;
    }
    else if (hi < N)
    {
        smax[cloc] = 0;
        scnt[cloc] = hi - lo + 1;
    }
    else
    {
        smax[cloc] = 0;
        scnt[cloc] = N - lo;
    }

    if (cloc < P)
    {
        int mid = (lo + hi) / 2;
        sfill (cloc * 2, lo, mid);
        sfill (cloc * 2 + 1, mid + 1, hi);
    }
}

void radd (int cloc, int start, int end, int rstart, int rend, int mult)
{
    if (cloc < P) prop (cloc);
    if (end < rstart)
        return;
    if (rend < start)
        return;
    if (rstart <= start && end <= rend)
    {
        smax[cloc] += mult;
        nprop[cloc] += mult;
        return;
    }

    int lo = start, hi = end;
    int mid = (start + end) / 2;
    radd (cloc * 2, lo, mid, rstart, rend, mult);
    radd (cloc * 2 + 1, mid + 1, hi, rstart, rend, mult);

    if (smax[2*cloc] == smax[2*cloc+1])
    {
        smax[cloc] = smax[2*cloc];
        scnt[cloc] = scnt[2*cloc] + scnt[2*cloc+1];
    }
    else if (smax[2*cloc] > smax[2*cloc+1])
    {
        smax[cloc] = smax[2*cloc];
        scnt[cloc] = scnt[2*cloc];
    }
    else
    {
        smax[cloc] = smax[2*cloc+1];
        scnt[cloc] = scnt[2*cloc+1];        
    }
}

void range_add (int cloc, int mult)
{
    int start = rord[cloc];
    int end = start + ssize[cloc] - 1;
    //cout << start << " " << end << " " << mult << endl;
    radd (1, 0, P - 1, start, end, mult);
}

int range_count (int x)
{
    if (smax[1] == x)
        return scnt[1];
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flood (0, 0);
    nord = 0;
    ford (0, 0);

    sfill (1, 0, P - 1);

    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) swap (x, y);

        int mult = 1;
        if (s.find(make_pair (x, y)) != s.end())
        {
            mult = -1;
            s.erase(make_pair (x, y));
        }
        else
        {
            s.insert(make_pair (x, y));
        }

        if (dep[x] > dep[y]) swap (x, y);

        if (is_anc (x, y))
        {
            int yt = get_anc (y, dep[y] - dep[x] - 1);

            range_add (0, mult);
            range_add (yt, -mult);
            range_add (y, mult);
        }
        else
        {
            range_add (x, mult);
            range_add (y, mult);
        }

        int ntot = s.size();
        cout << range_count (ntot) << "\n";
    }
}