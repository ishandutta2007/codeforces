#include <bits/stdc++.h>
using namespace std;

const int bits = 30;

int query(int c, int d)
{
    cout << "? " << c << " " << d << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int main()
{
    int c = 0, d = 0;
    int a = query(c, d);
    for(int pos = bits - 1; pos >= 0; pos--)
    {
        int b = query(c + (1 << pos), d + (1 << pos));
        if(a == b)
        {
            int x;
            if(a >= 0)
            {
                x = query(c, d + (1 << pos));
                if(x == 1)
                {
                    c += 1 << pos;
                    d += 1 << pos;
                }
            }
            else
            {
                x = query(c + (1 << pos), d);
                if(x == -1)
                {
                    c += 1 << pos;
                    d += 1 << pos;
                }
            }
        }
        else
        {
            if(a > 0)
                c += 1 << pos;
            else
                d += 1 << pos;
            a = query(c, d);
        }
        //cout << c << " " << d << endl;
    }
    cout << "! " << c << " " << d << endl;
}