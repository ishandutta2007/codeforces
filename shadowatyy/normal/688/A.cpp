#include <bits/stdc++.h>
using namespace std;

int n, d, result;

string t[107];

int res[107];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> d;

    for(int i = 1; i <= d; i++)
    {
        cin >> t[i];

        t[i] = '#' + t[i];

        for(int j = 1; j <= n; j++)
        {
            if(t[i][j]=='0')
            {
                res[i] = 1;
                break;
            }

            if(j==n)
            {
                res[i] = 0;
            }
        }
    }

    for(int i = 1; i <= d; i++)
    {
        if(res[i])
        {
            res[i] += res[i-1];
        }

        result = max(result, res[i]);
    }

    cout << result;
}