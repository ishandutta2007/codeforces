#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <deque>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int n, m;
bool seen[MAXN];
bool seen2[MAXN];
int state[MAXN];
bool good[MAXN];
vector <int> edge[MAXN];
vector <int> bedge[MAXN];

void flood (int loc)
{
    seen[loc] = true;
    for (int i = 0; i < edge[loc].size(); i++)
        if (!seen[edge[loc][i]])
            flood (edge[loc][i]);
}

void flood2 (int loc)
{
    seen2[loc] = true;
    if (state[loc] == 1)
        return;
    for (int i = 0; i < bedge[loc].size(); i++)
        if (!seen2[bedge[loc][i]])
            flood2 (bedge[loc][i]);
}

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        seen[i] = seen2[i] = good[i] = false;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> state[i];
    for (int i = 0; i < m; i++)
    {
        int t, t2;
        cin >> t >> t2; t--; t2--;
        edge[t].push_back (t2);
        bedge[t2].push_back (t);
    }
    for (int i = 0; i < n; i++)
        if (!seen[i] && (state[i] == 1))
            flood (i);
    for (int i = 0; i < n; i++)
        if (!seen2[i] && (state[i] == 2))
            flood2 (i);
    for (int i = 0; i < n; i++)
        cout << ((seen[i] && seen2[i]) ? 1 : 0) << "\n";
    //system ("Pause");
    return 0;
}