#include <iostream>
#include <vector>

using namespace std;

vector <int> edge[110];
bool seen[110];

void flood (int cur)
{
    if (seen[cur])
        return;
    seen[cur] = true;
    for (int a = 0; a < edge[cur].size(); a++)
        flood (edge[cur][a]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int temp, temp2;
    for (int a = 0; a < m; a++)
    {
        cin >> temp >> temp2;
        temp--; temp2--;
        edge[temp].push_back (temp2);
        edge[temp2].push_back (temp);
    }
    for (int a = 0; a < 110; a++)
        seen[a] = false;
    flood (0);
    bool check = true;
    for (int a = 0; a < n; a++)
        if (!seen[a])
            check = false;
    if (check && (n == m))
        cout << "FHTAGN!\n";
    else
        cout << "NO\n";
    return 0;
}