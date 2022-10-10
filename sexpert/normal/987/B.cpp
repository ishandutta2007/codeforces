#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if(x == y) cout << "=";
    else
    {
        if(min(x, y) >= 3)
        {
            if(x < y) cout << ">";
            else cout << "<";
        }
        else if(min(x, y) == 2)
        {
            if(max(x, y) >= 5)
            {
                if(x == 2) cout << ">";
                else cout << "<";
            }
            if(max(x, y) == 4) cout << "=";
            if(max(x, y) == 3)
            {
                if(x == 2) cout << "<";
                else cout << ">";
            }
        }
        else
        {
            if(x == 1) cout << "<";
            else cout << ">";
        }
    }
}