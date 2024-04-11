#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1000003;

int main()
{
    bool row[500100][2];
    bool col[500100][2];
    for (int a = 0; a < 500100; a++)
    {
        row[a][0] = false;
        row[a][1] = false;
        col[a][0] = false;
        col[a][1] = false;
    }
    int n, m;
    cin >> n >> m;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            char temp;
            cin >> temp;
            if (temp != '.')
            {
                int val = a;
                if (temp == '1' || temp == '4')
                    val++;
                col[b][val%2] = true;
                val = b;
                if (temp == '1' || temp == '2')
                    val++;
                row[a][val%2] = true;
            }
        }
    }
    int ans = 1;
    for (int a = 0; a < n; a++)
    {
        if (row[a][0] && row[a][1])
        {
            cout << 0 << "\n";
            return 0;
        }
        if (!row[a][0] && !row[a][1])
            ans = (ans * 2) % MOD;
    }
    for (int b = 0; b < m; b++)
    {
        if (col[b][0] && col[b][1])
        {
            cout << 0 << "\n";
            return 0;
        }
        if (!col[b][0] && !col[b][1])
            ans = (ans * 2) % MOD;
    }
    cout << ans << "\n";
    //system ("Pause");   
    return 0;
}