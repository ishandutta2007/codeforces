#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    char c[4][n];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c[i][j] = '.';
        }
    }
    cout << "YES\n";
    if(k % 2 == 0)
    {
        for(int i = 1; i <= k/2; i++)
        {
            c[1][i] = '#';
            c[2][i] = '#';
        }
    }
    else
    {
        if(k <= 3)
        {
            int m = n/2;
            c[1][m] = '#';
            if(k > 1)
            {
                c[1][m - 1] = '#';
                c[1][m + 1] = '#';
            }
        }
        else
        {
            c[1][1] = c[2][1] = c[1][2] = '#';
            for(int i = 3; i <= (k + 1)/2; i++)
            {
                c[1][i] = c[2][i] = '#';
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << c[i][j];
        }
        cout << endl;
    }
}