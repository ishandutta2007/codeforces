#include <bits/stdc++.h>
using namespace std;

int t, s, x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t >> s >> x;

    if(t>x)
    {
        cout << "NO";
        return 0;
    }

    if(t==x)
    {
        cout << "YES";
        return 0;
    }

    if(t<x)
    {
        x -= t;

        if(x==1)
        {
            cout << "NO";
            return 0;
        }

        x %= s;

        if(x==1 || x==0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }


}