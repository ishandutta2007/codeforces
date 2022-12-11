#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int x, y;
    string s;
    cin >> x >> y >> s;
    int dx = 0, dy = 0;
    char ch;
    for (int i = 0; i < s.length(); i++) {
        ch = s[i];
        if (dy == y && dx == x) {
            cout << "Yes";
            return 0;
        }
        if (ch == 'U') dy++;
        if (ch == 'D') dy--;
        if (ch == 'L') dx--;
        if (ch == 'R') dx++;
    }

    int xx = 0, yy = 0;

    for (int i = 0; i < s.length(); i++) {

        if (dx == 0 && xx == x && dy != 0 && abs(y - yy) % abs(dy) == 0 && (y - yy) / dy >= 0) {
            cout << "Yes";
            return 0;
        }

        if (dy == 0 && yy == y && dx != 0 && abs(x - xx) % abs(dx) == 0 && (x - xx) / dx >= 0) {
            cout << "Yes";
            return 0;
        }

        if (dx != 0 && dy != 0 && abs(x - xx) % abs(dx) == 0 && abs(y - yy) % abs(dy) == 0 && (x - xx) / dx == (y - yy) / dy && (y - yy) / dy >= 0) {
            cout << "Yes";
            return 0;
        }

        if (s[i] == 'L') xx--;
        if (s[i] == 'R') xx++;
        if (s[i] == 'U') yy++;
        if (s[i] == 'D') yy--;
    }

    cout << "No";

    return 0;
}