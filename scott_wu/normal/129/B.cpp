#include <iostream>

using namespace std;
const int MAXN = 110;

int n, m;
bool used[MAXN];
bool group[MAXN];
bool edge[MAXN][MAXN];
int num[MAXN];

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        num[i] = 0;
        used[i] = false;
        for (int j = 0; j < MAXN; j++)
            edge[i][j] = false;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int t, t2;
        cin >> t >> t2;
        t--; t2--;
        edge[t][t2] = edge[t2][t] = true;
        num[t]++; num[t2]++;
    }
    int ans = 0;
    while (true)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            group[i] = (num[i] == 1) && (!used[i]);
            found |= group[i];
        }
        if (!found)
            break;
        ans++;
        for (int i = 0; i < n; i++)
            if (group[i])
            {
                used[i] = true;
                for (int j = 0; j < n; j++)
                    if (edge[i][j])
                        num[j]--;
            }
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}