#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 3e5 + 34;

ll x1, x2, x3, y1, y2, y3;


int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 == x2 && x2 == x3) {cout << 1; return 0;}
    if (y1 == y2 && y2 == y3) {cout << 1; return 0;}

    if ((x1 == x2 || x1 == x3 || x2 == x3) && (y1 == y2 || y1 == y3 || y2 == y3))
        cout << 2;
    else {
        if (y1 == y2) {if ((x3 - x1) * (x3 - x2) > 0) cout << 2; else cout << 3;}
        else if (y1 == y3) {if ((x2 - x1) * (x2 - x3) > 0) cout << 2; else cout << 3;}
        else if (y2 == y3) {if ((x2 - x1) * (x3 - x1) > 0) cout << 2; else cout << 3;}

        else if (x1 == x2) {if ((y3 - y1) * (y3 - y2) > 0) cout << 2; else cout << 3;}
        else if (x1 == x3) {if ((y2 - y1) * (y2 - y3) > 0) cout << 2; else cout << 3;}
        else if (x2 == x3) {if ((y1 - y2) * (y1 - y3) > 0) cout << 2; else cout << 3;}
        
        else cout << 3;
    }


    return 0;
}