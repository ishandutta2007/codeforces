#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int , int > ipair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1234567;

const int N = 444;

int n, m;
bool e[N][N];
int bfs[N];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        e[a][b] = e[b][a] = true;
    }

    memset(bfs, 0x3f, sizeof(bfs));
    vector < int > q;
    q.push_back(0);
    bfs[0] = 0;
    for (int i = 0; i < q.size(); ++i)
    {
        int v = q[i];
        for (int nv = 0; nv < n; ++nv)
        {
            if (nv == v || e[v][nv] == e[0][n-1])
                continue;
            if (bfs[nv] > bfs[v] + 1)
            {
                bfs[nv] = bfs[v] + 1;
                q.push_back(nv);
            }
        }
    }

    cout << (bfs[n - 1] == IINF ? -1 : bfs[n-1]) << "\n";


    return 0;
}