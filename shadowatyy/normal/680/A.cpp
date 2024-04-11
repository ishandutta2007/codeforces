#include <bits/stdc++.h>
using namespace std;

int t[5];

int c2, c3, sum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for(int i = 0; i < 5; ++i)
    {
        cin >> t[i];

        sum += t[i];
    }

    sort(t, t+5);

    for(int i = 0; i < 3; ++i)
    {
        if(t[i]==t[i+1] && t[i+1]==t[i+2])
        {
            c3 = max(c3, t[i]*3);
        }
    }

    for(int i = 0; i < 4; ++i)
    {
        if(t[i]==t[i+1])
        {
            c2 = max(c2, t[i]*2);
        }
    }

    cout << min(sum, min(sum-c2, sum-c3));
}