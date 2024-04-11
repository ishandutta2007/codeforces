#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 510000;
const ll MOD = 1e9 + 7;

int N, M, K;
ll arr[MAXN];
map <ll, vector <pair <int, int> > > mm;
ll p2[MAXN];

vector <int> e[MAXN];
bool seen[MAXN];
int nn;

void flood (int cloc)
{
    if (seen[cloc]) return;
    nn--;
    seen[cloc] = true;
    for (int i = 0; i < e[cloc].size(); i++)
        flood(e[cloc][i]);
}

void drop (int x)
{
    if (seen[x]) return;
    nn++;
    flood (x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    p2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        p2[i] = (2 * p2[i-1]) % MOD;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        x--, y--;
        mm[arr[x] ^ arr[y]].push_back(make_pair (x, y));
    }

    ll ans = p2[N+K];
    for (map<ll, vector<pair<int, int> > >::iterator it = mm.begin(); it != mm.end(); it++)
    {
        vector <pair <int, int> > edges = it->second;

        for (int i = 0; i < edges.size(); i++)
        {
            e[edges[i].first].push_back(edges[i].second);
            e[edges[i].second].push_back(edges[i].first);
        }

        nn = N;
        for (int i = 0; i < edges.size(); i++)
        {
            drop (edges[i].first);
            drop (edges[i].second);
        }

        for (int i = 0; i < edges.size(); i++)
        {
            e[edges[i].first].clear();
            e[edges[i].second].clear();
            seen[edges[i].first] = seen[edges[i].second] = false;
        }

        ans = (ans + p2[nn] - p2[N] + MOD) % MOD;
    }
    cout << ans << "\n";
}