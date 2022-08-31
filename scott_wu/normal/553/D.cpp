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
typedef long double ld;
const int MAXN = 100100;
const ld EPS = 1e-12;

int N, M, K;
vector <int> edge[MAXN];
vector <int> fort;
int life[MAXN];

vector <int> q;

bool solve (ld x)
{
    q.clear();
    for (int i = 0; i < N; i++)
    {
        int r = edge[i].size() * x;
        if (edge[i].size() * x - (ld) r < EPS)
            r--;
        life[i] = edge[i].size() - r - 1;
    }
    
    for (int i = 0; i < fort.size(); i++)
    {
        q.push_back (fort[i]);
        life[fort[i]] = -1;
    }
    
    for (int i = 0; i < q.size(); i++)
    {
        int cloc = q[i];
        for (int j = 0; j < edge[cloc].size(); j++)
        {
            int neigh = edge[cloc][j];
            life[neigh]--;
            if (life[neigh] == -1)
                q.push_back (neigh);
        }
    }
    
    //cout << x << " " << q.size() << "\n";
    return q.size() < N;
}

vector <int> res;

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> K;
    fort.clear();
    for (int i = 0; i < K; i++)
    {
        int x; cin >> x;
        fort.push_back (x - 1);
    }
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back (b);
        edge[b].push_back (a);
    }
    
    ld lo = 0, hi = 1;
    for (int i = 0; i < 80; i++)
    {
        ld mid = (lo + hi) / (ld) 2;
        if (solve (mid))
            lo = mid;
        else
            hi = mid;
    }
    solve (lo - EPS);
    
    res.clear();
    for (int i = 0; i < N; i++)
        if (life[i] >= 0)
            res.push_back (i + 1);
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    return 0;
}