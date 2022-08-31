#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
const int MAXN = 310;

int n;
int pref[MAXN][MAXN]; // alex pref = [0][i]
int loc[MAXN][MAXN]; // [i][j], loc of pres. j in friend i
int best[2] = {-1, -1};
int ans[MAXN], t[MAXN];

void ubest (int i)
{
    if (best[1] == -1 || loc[0][i] < loc[0][best[1]])
    {
        best[1] = i;
        if (best[0] == -1 || loc[0][i] < loc[0][best[0]])
            swap (best[0], best[1]);
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        ans[i] = t[i] = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> pref[i][j];
            pref[i][j]--;
            loc[i][pref[i][j]] = j;
        }
    for (int i = 0; i < n; i++)
    {
        cin >> pref[0][i];
        pref[0][i]--;
        loc[0][pref[0][i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        ubest (i);
        for (int j = 0; j < n; j++)
        {
            if (j != best[0] && best[0] != -1)
            {
                if (ans[j] == -1 || loc[j+1][best[0]] < loc[j+1][ans[j]])
                {
                    ans[j] = best[0];
                    t[j] = i + 1;
                }
            }
            else if (best[1] != -1)
            {
                if (ans[j] == -1 || loc[j+1][best[1]] < loc[j+1][ans[j]])
                {
                    ans[j] = best[1];
                    t[j] = i + 1;
                }
            }
        }
    }
    string sep = "";
    for (int i = 0; i < n; i++)
    {
        cout << sep << t[i];
        sep = " ";
    }
    cout << "\n";
    //system ("Pause");
    return 0;
}