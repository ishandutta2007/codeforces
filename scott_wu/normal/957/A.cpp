#include <iostream>

using namespace std;

int N;
char c[110];
int d[110];
int dp[110][3];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> c[i];

    for (int i = 0; i < N; i++)
    {
        d[i] = -1;
        if (c[i] == 'C')
            d[i] = 0;
        if (c[i] == 'Y')
            d[i] = 1;
        if (c[i] == 'M')
            d[i] = 2;
    }

    bool bad = false;
    bool found2 = false;
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && d[i] == d[i-1] && d[i] != -1)
        {
            bad = true;
            break;
        }

        if (d[i] != -1)
            continue;
        int nb = 3;
        for (int j = 0; j < 3; j++)
        {
            if ((i > 0 && d[i-1] == j) || (i < N - 1 && d[i+1] == j))
                nb--;
        }
        if (nb >= 2)
            found2 = true;
    }
    if (bad || !found2)
        cout << "No\n";
    else
        cout << "Yes\n";
}