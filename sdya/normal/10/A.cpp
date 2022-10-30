#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, p1, p2, p3, t1, t2;
int l[200], r[200];

int main()
{
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    int res = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> l[i] >> r[i];
        res += (r[i] - l[i]) * p1;
    }

    for (int i = 1; i < n; i ++)
    {
        int s = l[i + 1] - r[i];
        if (s >= t1 + t2) 
        {
            res += t1 * p1 + t2 * p2 + (s - t1 - t2) * p3;
        } else
        if (s >= t1)
        {
            res += t1 * p1 + (s - t1) * p2;
        } else
            res += s * p1;
    }
    cout << res << endl;
    return 0;
}