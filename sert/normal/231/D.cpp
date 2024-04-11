#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e3 + 34;
const ld EPS = 1e-4;

int a[10], xx, yy, zz ,x, y, z, sum;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> x >> y >> z;
    cin >> xx >> yy >> zz;
    for (int i = 1; i <= 6; i++) cin >> a[i];

    if (x > xx) sum += a[6];
    if (x < 0) sum += a[5];

    if (y > yy) sum += a[2];
    if (y < 0) sum += a[1];

    if (z > zz) sum += a[4];
    if (z < 0) sum += a[3];
    cout << sum;


    return 0;
}