#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int test = 0; test < n; test++)
    {
        int s, f, t;
        cin >> s >> f >> t; s--; f--;
        if (s == f)
        {
            cout << t << "\n";
            continue;
        }
        int newt = t % (2 * m - 2);
        int btime, ctime;
        if (s == 0)
        {
            if (newt > 0) btime = t - newt + 2 * m - 2;
            else btime = t;
        }
        else if (s == m - 1)
        {
            if (newt < m) btime = t - newt + m - 1;
            else btime = t - newt + 2 * m - 2 + m - 1;
        }
        else
        {
            int s1 = s, s2 = 2 * m - 2 - s;
            if (newt <= s1) btime = t - newt + s1;
            else btime = t - newt + 2 * m - 2 + s1;
            if (newt <= s2) btime = min (btime, t - newt + s2);
            else btime = min (btime, t - newt + 2 * m - 2 + s2);
        }
        newt = btime % (2 * m - 2);
        if (f == 0)
        {
            if (newt > 0) ctime = btime - newt + 2 * m - 2;
            else ctime = btime;
        }
        else if (f == m - 1)
        {
            if (newt < m) ctime = btime - newt + m - 1;
            else ctime = btime - newt + 2 * m - 2 + m - 1;
        }
        else
        {
            int f1 = f, f2 = 2 * m - 2 - f;
            if (newt <= f1) ctime = btime - newt + f1;
            else ctime = btime - newt + 2 * m - 2 + f1;
            if (newt <= f2) ctime = min (ctime, btime - newt + f2);
            else ctime = min (ctime, btime - newt + 2 * m - 2 + f2);
        }
        cout << ctime << "\n";
    }
    //system ("Pause");
    return 0;
}