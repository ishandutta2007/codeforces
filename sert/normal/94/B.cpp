#include <iostream>

using namespace std;

int main()
{
    int fail = 1;
    int z[20][20], p, v;
    int k, n;
    cin >> n;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            z[i][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> p;
        z[v][p] = 1;
        z[p][v] = 1;
    }

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            for (int ii = 1; ii <= 5; ii++)
            {
                k = z[i][j] + z[i][ii] + z[j][ii];
                if ((i - j) * (i - ii) * (j - ii) > 0)
                    if (k % 3 == 0) fail = 0;
                if ((i - j) * (i - ii) * (j - ii) < 0)
                    if (k % 3 == 0) fail = 0;
            }

    if (fail == 1) cout << "FAIL";
    else cout << "WIN";


    return 0;
}