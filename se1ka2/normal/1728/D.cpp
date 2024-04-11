#include <iostream>
using namespace std;

bool b[2005][2005][2];
int d[2005][2005][2];

int rec(int l, int r, string &s, bool f)
{
    if (b[l][r][f])
    {
        return d[l][r][f];
    }
    b[l][r][f] = true;
    if (l == r)
    {
        return d[l][r][f] = 2;
    }
    char last;
    if(!f && l > 0)
    {
        last = s[l - 1];
    }
    else if(r < (int)s.size())
    {
        last = s[r];
    }
    if ((r - l) % 2)
    {
        if (rec(l + 1, r, s, 0) == 1 || (rec(l + 1, r, s, 0) == 2 && s[l] < last))
        {
            return d[l][r][f] = 1;
        }
        if (rec(l, r - 1, s, 1) == 1 || (rec(l, r - 1, s, 1) == 2 && s[r - 1] < last))
        {
            return d[l][r][f] = 1;
        }
        if ((rec(l + 1, r, s, 0) == 2 && s[l] == last) || (rec(l, r - 1, s, 1) == 2 && s[r - 1] == last))
        {
            return d[l][r][f] = 2;
        }
        return d[l][r][f] = 0;
    }
    else
    {
        if (rec(l + 1, r, s, 0) == 0)
        {
            return d[l][r][f] = 0;
        }
        if (rec(l, r - 1, s, 1) == 0)
        {
            return d[l][r][f] = 0;
        }
        if (rec(l + 1, r, s, 0) == 2 || rec(l, r - 1, s, 1) == 2)
        {
            return d[l][r][f] = 2;
        }
        return d[l][r][f] = 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        for (int l = 0; l <= n; l++)
        {
            for (int r = 0; r <= n; r++)
            {
                b[l][r][0] = b[l][r][1] = false;
            }
        }
        int ans = rec(0, n, s, 'a');
        if (ans == 0)
        {
            cout << "Alice" << endl;
        }
        if (ans == 1)
        {
            cout << "Bob" << endl;
        }
        if (ans == 2)
        {
            cout << "Draw" << endl;
        }
    }
}