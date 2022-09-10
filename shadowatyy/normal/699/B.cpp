#include <bits/stdc++.h>
using namespace std;

int n, m, c;

char t[1007][1007];

int res[1007][1007];

void oznacz(int y, int x)
{
    for(int i = 1; i <= n; ++i)
    {
        ++res[i][x];
    }

    for(int j = 1; j <= m; ++j)
    {
        ++res[y][j];
    }

    --res[y][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> t[i][j];

            if(t[i][j]=='*')
            {
                ++c;
            }
        }
    }

    if(c>=n+m)
    {
        cout << "NO";
        return 0;
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(t[i][j]=='*')
            {
                oznacz(i, j);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(res[i][j]==c)
            {
                cout << "YES\n" << i << " " << j;
                return 0;
            }
        }
    }

    cout << "NO";

}