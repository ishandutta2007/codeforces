#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num[11][2];
string str;
vector <int> ans[2];

int main()
{
    for (int i = 0; i < 11; i++)
        num[i][0] = num[i][1] = 0;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        for (int j = 0; j < 2; j++)
            num[(int) str[i] - '0'][j]++;
    int best = 0, loc = 5;
    for (int i = 1; i <= 5; i++)
    {
        if (num[i][0] > 0 && num[10-i][1] > 0)
        {
            int count = 1;
            num[i][0]--;
            num[10-i][1]--;
            for (int j = 1; j <= 8; j++)
                count += min (num[j][0], num[9-j][1]);
            if (count >= best)
            {
                best = count;
                loc = i;
            }
            num[i][0]++;
            num[10-i][1]++;
        }
    }
    if (best > 0)
    {
        for (int i = 0; i < num[0][0] - num[9][0]; i++)
        {
            ans[0].push_back (0);
            ans[1].push_back (0);
        }
        num[0][0] -= max (num[0][0] - num[9][0], 0);
        num[0][1] -= max (num[0][1] - num[9][0], 0);
        ans[0].push_back (loc);
        ans[1].push_back (10-loc);
        num[loc][0]--;
        num[10-loc][1]--;
        for (int i = 0; i <= 9; i++)
        {
            while (min (num[i][0], num[9-i][1]) > 0)
            {
                num[i][0]--;
                num[9-i][1]--;
                ans[0].push_back (i);
                ans[1].push_back (9-i);
            }
        }
    }
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < num[i][j]; k++)
                ans[j].push_back (i);
    for (int i = ans[0].size() - 1; i >= 0; i--)
        cout << ans[0][i];
    cout << "\n";
    for (int i = ans[1].size() - 1; i >= 0; i--)
        cout << ans[1][i];
    cout << "\n";
    //system ("Pause");
    return 0;
}