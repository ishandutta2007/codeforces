#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

int main()
{
    long int a[1000], q, mas, h, p, s, i, j, k, n, fail, rez = 0, x1[102], y1[102], y2[102], x2[102], m[102];
    long double x, y;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        k = abs(x1[i] - x2[i]);
        m[i] = k * k * k;
    }
    //cout << endl;
    for (i = 1; i <= n; i++)
    {
        fail = 0;
        for (j = 2; j <= i; j++)
        {
            x = 0;
            y = 0;
            p = 0;
            s = 0;
            for (h = j; h <= i; h++)
            {
                x = x + (x1[h] + x2[h]) * m[h]/ 2;
                y = y + (y1[h] + y2[h]) * m[h]/ 2;
            }
                mas = 0;
                for (q = j; q <= i; q++)mas = mas + m[q];
                //cout << x << " " << y << "|";
                x = x / (mas);
                y = y / (mas);
                //cout << x << " " << y << " " << j << " " << i << " " << mas << endl;
                if ((x1[j-1] - x)*(x2[j-1] - x) > 0) {cout << rez; return 0;}
                if ((y1[j-1] - y)*(y2[j-1] - y) > 0) {cout << rez; return 0;}

        }
        rez = i;
    }
    cout << rez << endl;
    return 0;
}