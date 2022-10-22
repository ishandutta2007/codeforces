#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c[3], r[3];
        int d = 0;
        bool b[2][2];
        b[0][0] = b[0][1] = b[1][0] = b[1][1] = false;
        for(int i = 0; i < 3; i++)
        {
            cin >> c[i] >> r[i];
            b[c[i] % 2][r[i] % 2] = true;
            if(c[i] == 1 || c[i] == n)
            {
                d++;
            }
            if(r[i] == 1 || r[i] == n)
            {
                d++;
            }
        }
        int x, y;
        cin >> x >> y;
        if(b[x % 2][y % 2])
        {
            if(d <= 3)
            {
                cout << "YES" << endl;
            }
            else
            {
                int dc = 0, dr = 0;
                for(int i = 0; i < 3; i++)
                {
                    if(x == c[i])
                    {
                        dc++;
                    }
                    if(y == r[i])
                    {
                        dr++;
                    }
                }
                if(dc == 2 || dr == 2)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}