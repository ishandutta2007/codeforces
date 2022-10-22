#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string x, y;
    int lasty, lastx;
    for (int qq = 0; qq < t; qq++) {
        cin >> x >> y;
        //cout << x << " " << y << " ";
        lasty = 0;
        int ind = y.length()-1;
        while (ind >= 0 && y[ind] == '0') {
            ind--;
            lasty++;
        }
        //cout << ind << "!";
        if (ind < 0) {
            cout << "0" << endl;
            continue;
        }
        lastx = lasty;
        ind = x.length() - 1 - lastx;
        while (ind >= 0 && x[ind] == '0') {
            ind--;
            lastx++;
        }
        //cout << ind << "!";
        cout << lastx - lasty << endl;
    }
    return 0;
}