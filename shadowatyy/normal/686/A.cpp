#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, x, d, dist;

char c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> x;

    for(int i = 1; i <= n; i++)
    {
        cin >> c >> d;

        if(c=='-')
        {
            if(x-d>=0)
            {
                x -= d;
            }
            else
            {
                dist++;
            }
        }
        else
        {
            x += d;
        }
    }

    cout << x << " " << dist;
}