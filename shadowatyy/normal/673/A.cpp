#include <bits/stdc++.h>
using namespace std;

int t[97];

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    t[n+1] = 1000000;

    for(int i = 0; i <= n; i++)
    {
        if(t[i]+15<t[i+1])
        {
            cout << min(t[i]+15, 90);
            return 0;
        }
    }
}