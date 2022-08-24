#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M;
vector <int> edge[MAXN];
bool seen[MAXN];
bool good;

void flood (int cloc)
{
    if (edge[cloc].size() != 2)
        good = false;
    seen[cloc] = true;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (seen[neigh])
            continue;
        flood(neigh);
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        seen[i] = false;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (!seen[i])
        {
            good = true;
            flood(i);
            if (good)
                ans++;
        }
    }
    cout << ans << "\n";
}