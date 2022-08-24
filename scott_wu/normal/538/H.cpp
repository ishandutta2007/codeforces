#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int L, H;
int N, M;
pair <int, int> t[MAXN];
vector <int> edge[MAXN];

int res[MAXN]; // 1 or 2

bool good (pair <int, int> r, int x)
{
    return x >= r.first && x <= r.second;
}

void flood (int cloc, int val)
{
    //cout << cloc << " " << val << " " << res[cloc] << "\n";
    if (res[cloc] == val) return;
    if (res[cloc] == 3 - val)
    {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    
    res[cloc] = val;
    for (int i = 0; i < edge[cloc].size(); i++)
        flood (edge[cloc][i], 3 - val);
}

bool run (int x, int y)
{
    if (x < 0 || y < 0)
    {
        return false;
    }
    
    for (int i = 0; i < MAXN; i++)
        res[i] = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (!good(t[i], x) && !good (t[i], y))
            return false;
        
        if (!good(t[i], x))
            flood (i, 2);
        if (!good(t[i], y))
            flood (i, 1);
    }
    
    for (int i = 0; i < N; i++)
        if (res[i] == 0)
            flood (i, 1);
    
    cout << "POSSIBLE\n";
    cout << x << " " << y << "\n";
    for (int i = 0; i < N; i++)
        cout << res[i];
    cout << "\n";
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> L >> H >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> t[i].first >> t[i].second;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back (b);
        edge[b].push_back (a);
    }
    
    int tlo = 1e9, thi = -1;
    for (int i = 0; i < N; i++)
    {
        tlo = min (tlo, t[i].second);
        thi = max (thi, t[i].first);
    }
    
    if (tlo + thi < L)
    {
        thi = L - tlo;
    }
    else if (tlo + thi > H)
    {
        tlo = H - thi;
    }
    
    if (!run (tlo, thi))
        cout << "IMPOSSIBLE\n";
    return 0;
}