#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const int MAXN = 200100;

int N;
vector <int> edge[MAXN];
bool live[MAXN];
int deg[MAXN];
vector <int> ans;

void clean (int cloc, int last)
{
    if (!live[cloc]) return;
    live[cloc] = false;
    ans.push_back(cloc);
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh == last)
            continue;

        clean (neigh, cloc);
    }
}

void run (int cloc, int last)
{
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh == last)
            continue;

        run (neigh, cloc);
    }

    if (deg[cloc] % 2 == 1)
    {
        return;
    }

    if (last != -1)
    {
        deg[last]--;
    }
    clean(cloc, last);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x)
        {
            edge[x-1].push_back(i);
            edge[i].push_back(x-1);
        }
        live[i] = true;
    }

    for (int i = 0; i < N; i++)
        deg[i] = edge[i].size();

    ans.clear();
    run(0, -1);

    if (ans.size() != N)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 0; i < N; i++)
            cout << ans[i] + 1 << "\n";
    }
}