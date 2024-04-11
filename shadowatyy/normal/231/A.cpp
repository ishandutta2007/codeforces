#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, w, c, res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        c = 0;

        for(int j = 1; j <= 3; j++)
        {
            cin >> w;

            c += w;
        }

        if(c>1)
        {
            res++;
        }
    }

    cout << res;
}