#include <bits/stdc++.h>
using namespace std;

string d;

int a, b;

char c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> c;

    a = int(c-48);

    cin >> c;

    cin >> c;

    while(c!='e')
    {
        d.push_back(c);

        cin >> c;
    }

    cin >> b;

    if(b<d.size())
    {
        d.insert(b, ".");

        if(d==".0")
        {
            cout << a;
        }
        else
        {
            cout << a << d;
        }
    }
    else
    {
        if(b==d.size())
        {
            if(d==".0")
            {
                cout << a;
            }
            else
            {
                cout << a << d;
            }
        }
        else
        {
            if(b>d.size())
            {
                int m = b-d.size();

                for(int i = 1; i <= m; ++i)
                {
                    d.push_back('0');
                }

                if(d==".0")
                {
                    cout << a;
                }
                else
                {
                    cout << a << d;
                }
            }
        }

    }


}