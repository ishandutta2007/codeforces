#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s1, s0;
    cin >> n >> s1;
    int r[3], g[3], b[3];
    for (int i = 0; i < 3; i++)
    {
        r[i] = 0;
        g[i] = 0;
        b[i] = 0;
    }
    int k;
    for (k = 0; k + 2 < n; k+=3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (s1[k+i] == 'R')
            {
                g[i]++;
                b[i]++;
            }
            else if (s1[k+i] == 'G')
            {
                r[i]++;
                b[i]++;
            }
            else if (s1[k+i] == 'B')
            {
                g[i]++;
                r[i]++;
            }
        }
    }
    //cout << k << endl;
    if (k < n)
    {
        if (s1[k] == 'R')
        {
            g[0]++;
            b[0]++;
        }
        else if (s1[k] == 'G')
        {
            r[0]++;
            b[0]++;
        }
        else if (s1[k] == 'B')
        {
            g[0]++;
            r[0]++;
        }
    }
    if (k + 1 < n)
    {
        if (s1[k + 1] == 'R')
        {
            g[1]++;
            b[1]++;
        }
        else if (s1[k + 1] == 'G')
        {
            r[1]++;
            b[1]++;
        }
        else if (s1[k + 1] == 'B')
        {
            g[1]++;
            r[1]++;
        }
    }
    /*for (int i = 0; i < 3; i++)
    {
        cout << "r[" << i << "]=" << r[i] << endl;
        cout << "g[" << i << "]=" << g[i] << endl;
        cout << "b[" << i << "]=" << b[i] << endl;
    }*/
    int rmin;
    rmin = r[0] + g[1] + b[2];
    s0 = "RGB";
    if (rmin > r[0] + b[1] + g[2])
    {
        s0 = "RBG";
        rmin = r[0] + b[1] + g[2];
    }
    if (rmin > r[1] + b[2] + g[0])
    {
        s0 = "GRB";
        rmin = r[1] + b[2] + g[0];
    }
    if (rmin > r[2] + b[1] + g[0])
    {
        s0 = "GBR";
        rmin = r[2] + b[1] + g[0];
    }
    if (rmin > r[1] + b[0] + g[2])
    {
        s0 = "BRG";
        rmin = r[1] + b[0] + g[2];
    }
    if (rmin > r[2] + b[0] + g[1])
    {
        s0 = "BGR";
        rmin = r[2] + b[0] + g[1];
    }

    cout << rmin << endl;

    for (int i = 0; i + 2 < n; i+=3)
        cout << s0;
    if (k < n)
    {
        cout << s0[0];
    }
    if (k+1 < n)
    {
        cout << s0[1];
    }

    return 0;
}