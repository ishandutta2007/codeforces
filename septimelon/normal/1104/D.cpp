#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string s1;
    char ans;
    long long int x, y, buf;
    while (true)
    {
        cin >> s1;
        if (s1 == "end" || s1 == "mistake")
            return 0;
        y = 0; x = 1;
        buf = 1;
        ans = 'x';
        while (ans == 'x' && buf < 500000000)
        {
            y = x;
            x *= 2;
            buf = x - y;
            cout << "? " << x << " " << y << endl;
            fflush(stdout);
            cin >> ans;
        }
        if (ans == 'e')
            return 0;
        if (ans == 'x')
        {
            cout << "! " << 1 << endl;
            fflush(stdout);
        }
        else
        {
            while (buf > 1)
            {
                buf /= 2;
                x = y + buf;
                cout << "? " << x << " " << y << endl;
                fflush(stdout);
                cin >> ans;
                if (ans == 'e')
                    return 0;
                if (ans == 'x')
                    y = x;
            }
            x = y+1;
            cout << "! " << x << endl;
            fflush(stdout);
        }
    }
    return 0;
}