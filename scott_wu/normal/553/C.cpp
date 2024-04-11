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
const ll MOD = 1e9 + 7;

int N, M;
vector <pair <int, int> > edge[MAXN];

int cval[MAXN];
bool good;

void flood (int cloc, int val)
{
    if (cval[cloc] != -1)
    {
        if (cval[cloc] != val)
            good = false;
        return;
    }
    
    cval[cloc] = val;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i].first;
        flood (neigh, (val + edge[cloc][i].second + 1) % 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    good = true;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cval[i] = -1;
    
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[a].push_back (make_pair (b, c));
        edge[b].push_back (make_pair (a, c));
    }
    
    int cnt = 0;
    ll res = 1;
    for (int i = 0; i < N; i++)
        if (cval[i] == -1)
        {
            if (cnt) res = (res * 2) % MOD;
            cnt++;
            
            flood (i, 0);
        }
    
    if (good)
        cout << res << "\n";
    else
        cout << "0\n";
    return 0;
}