#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
vector <pair <int, int> > edge[MAXN];
bool bad[MAXN];
int w[MAXN];

int ssize[MAXN];
int par[MAXN];

double res;

void gflood (int cloc, int last, double tot)
{
    res += tot * sqrt (tot) * w[cloc];
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i].first;
        if (neigh == last) continue;
        gflood (neigh, cloc, tot + edge[cloc][i].second);
    }
}

double get (int loc)
{
    res = 0;
    gflood (loc, -1, 0);
    return res;
}

vector <int> v;
void flood (int cloc, int last)
{
    v.push_back (cloc);
    ssize[cloc] = 1;
    par[cloc] = last;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i].first;
        if (neigh == last || bad[neigh]) continue;
        flood (neigh, cloc);
        ssize[cloc] += ssize[neigh];
    }
}

int runs;

int solve (int loc)
{
    runs++;
    v.clear();
    flood (loc, -1);
    if (v.size() == 1)
        return loc;
    
    int bloc = -1, btot = -1;
    for (int i = 0; i < v.size(); i++)
    {
        int p = v[i];
        if (ssize[p] <= v.size() / 2 && ssize[p] > btot)
        {
            btot = ssize[p];
            bloc = p;
        }
    }
    
    int a = bloc, b = par[bloc];
    if (get (a) > get (b))
        swap (a, b);
    bad[b] = true;
    
    if (runs > 70) return a;
    return solve (a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    for (int i = 0; i < MAXN; i++)
        bad[i] = false;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> w[i];
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[a].push_back (make_pair (b, c));
        edge[b].push_back (make_pair (a, c));
    }
    
    runs = 0;
    int ans = solve (0);
    
    cout << fixed << setprecision(9);
    cout << ans + 1 << " " << get (ans) << "\n";
    
    return 0;
}