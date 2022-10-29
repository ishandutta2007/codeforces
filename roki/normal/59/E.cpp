#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
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

int n, m, k;
unordered_set<li> pr;
vector<int> g[3000];

bool read()
{
    if(!(cin >> n >> m >> k))
        return false;
    forn (i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn (i, k)
    {
        li a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        pr.insert(a * 3000 * 3000 + b * 3000 + c);
    }
    return true;
}

void solve()
{
    queue<pair<int, int>> q;
    int d[3000][3000];
    pair<int, int> from[3000][3000];
      forn(i, n)
      forn(j, n)
      d[i][j] = 1e9;
    q.push(mp(n - 1, -1));
    while(!q.empty())
    {
        int v = q.front().first;
       // cout << v << endl;
        int fr = q.front().second;
        q.pop();
        if(v == 0)
        {
            cout << d[v][fr] << endl;
            while(v != n - 1)
            {
                cout << v + 1 << ' ';
                int nv = from[v][fr].first;
                int nfr = from[v][fr].second;
                v = nv, fr = nfr;
            }
            cout << n << endl;
            return;
        }
        forn (i, g[v].size())
        {
            li to = g[v][i];
            //cout << to << endl;
            if(v == n - 1 || pr.count(to * 3000 * 3000 + v * 3000 + fr) == 0)
            {
               // cout << d[to][v];
                if(d[to][v] == 1e9)
                {
                    q.push(mp(to, v));
                    d[to][v] = fr == -1 ? 1 : d[v][fr] + 1;
                    from[to][v] = mp(v, fr);
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}