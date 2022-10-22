#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    string s;
    ll x, y;
    ll minx, miny, maxx, maxy;
    ll minxf, minxl, maxxf, maxxl;
    ll minyf, minyl, maxyf, maxyl;
    ll grid;
    for (int i = 0; i < t; i++) {
        cin >> s;
        x = 0;
        y = 0;
        minx = 0;
        maxx = 0;
        miny = 0;
        maxy = 0;
        minxf = 0; minxl = 0; maxxf = 0; maxxl = 0;
        minyf = 0; minyl = 0; maxyf = 0; maxyl = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'W') {
                y++;
                if (y == maxy) {
                    maxyl = i;
                }
                else if (y > maxy) {
                    maxy = y;
                    maxyf = i;
                    maxyl = i;
                }
            }
            else if (s[i] == 'S') {
                y--;
                if (y == miny) {
                    minyl = i;
                }
                else if (y < miny) {
                    miny = y;
                    minyf = i;
                    minyl = i;
                }
            }
            else if (s[i] == 'D') {
                x++;
                if (x == maxx) {
                    maxxl = i;
                }
                else if (x > maxx) {
                    maxx = x;
                    maxxf = i;
                    maxxl = i;
                }
            }
            else if (s[i] == 'A') {
                x--;
                if (x == minx) {
                    minxl = i;
                }
                else if (x < minx) {
                    minx = x;
                    minxf = i;
                    minxl = i;
                }
            }
        }
        grid = (maxx - minx + 1) * (maxy - miny + 1);
        if ((maxxl < minxf || minxl < maxxf) && maxx - minx > 1)
            grid = (maxx - minx) * (maxy - miny + 1);
        if ((maxyl < minyf || minyl < maxyf) && maxy - miny > 1)
            grid = min(grid, (maxx - minx + 1) * (maxy - miny));
        cout << grid << endl;
    }
    return 0;
}