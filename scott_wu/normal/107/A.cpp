#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 1100;

int tap[MAXN];
int diam[MAXN];
bool tank[MAXN];
int n, p;

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        tank[i] = true;
        tap[i] = -1;
    }
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        int temp, temp2, temp3;
        cin >> temp >> temp2 >> temp3;
        temp--; temp2--;
        tap[temp] = temp2;
        diam[temp] = temp3;
        tank[temp2] = false;
    }
    int ans[1100][3];
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (tank[i] && (tap[i] != -1))
        {
            int dia = diam[i];
            int loc = i;
            while (tap[loc] != -1)
            {
                dia = min (dia, diam[loc]);
                loc = tap[loc];
            }
            ans[cur][0] = i + 1;
            ans[cur][1] = loc + 1;
            ans[cur][2] = dia;
            cur++;
        }
    }
    cout << cur << "\n";
    for (int i = 0; i < cur; i++)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
    //system ("Pause");
    return 0;
}