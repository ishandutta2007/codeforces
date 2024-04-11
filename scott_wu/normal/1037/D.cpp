#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
vector <int> edge[MAXN];
int goal[MAXN];
int ord[MAXN];

bool cmp (int left, int right)
{
    return ord[left] < ord[right];
}

bool seen[MAXN];
vector <int> q;

void bfs()
{
    for (int i = 0; i < MAXN; i++)
        seen[i] = false;
    q.clear();

    q.push_back(0);
    seen[0] = true;
    for (int i = 0; i < q.size(); i++)
    {
        int cloc = q[i];
        for (int j = 0; j < edge[cloc].size(); j++)
        {
            int neigh = edge[cloc][j];
            //cout << i << " " << cloc << " " << neigh << "\n";
            if (!seen[neigh])
            {
                q.push_back(neigh);
                seen[neigh] = true;
                //cout << neigh << "\n";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> goal[i];
        goal[i]--;
        ord[goal[i]] = i;
    }

    for (int i = 0; i < N; i++)
    {
        sort (edge[i].begin(), edge[i].end(), cmp);
    }

    bfs();

    bool bad = false;
    for (int i = 0; i < N; i++)
        if (q[i] != goal[i])
            bad = true;
    if (!bad) cout << "Yes\n";
    else cout << "No\n";
}