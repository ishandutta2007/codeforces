#include <bits/stdc++.h>

#define ff first
#define ss second
#define y1 yy1

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll x1, y1, x2, y2;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2;
    if (y2 >= y1 + x1 || x2 >= y1 + x1 || (x2 >= x1 && y2 >= y1))
        cout << "Polycarp\n";
    else
        cout << "Vasiliy\n";
    return 0;
}