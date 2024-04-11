#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int MAXS = 110;

int N, M, S, K;
int D[MAXS][MAXN];
vector <int> edge[MAXN];
bool seen[MAXN];
int a[MAXN];

vector <int> q;
vector <int> v;

void sdist (int k)
{
    for (int i = 0; i < N; i++)
    {
        seen[i] = false;
        D[k][i] = 1e9;
    }
    q.clear();

    for (int i = 0; i < N; i++)
    {
        if (a[i] == k)
        {
            seen[i] = true;
            D[k][i] = 0;
            q.push_back(i);
        }
    }

    for (int i = 0; i < q.size(); i++)
    {
        int cur = q[i];
        int cdist = D[k][cur];

        for (int j = 0; j < edge[cur].size(); j++)
        {
            int neigh = edge[cur][j];
            if (D[k][neigh] > cdist + 1)
            {
                D[k][neigh] = cdist + 1;
                q.push_back(neigh);
                seen[neigh] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    for (int i = 0; i < K; i++)
    {
        sdist(i);
    }

    for (int i = 0; i < N; i++)
    {
        v.clear();
        for (int j = 0; j < K; j++)
            v.push_back(D[j][i]);
        sort(v.begin(), v.end());

        long long ans = 0;
        for (int j = 0; j < S; j++)
            ans += v[j];
        cout << ans << " ";
    }
    cout << "\n";
}