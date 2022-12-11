#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int x, y, minx = N, miny = N, maxx = -N, maxy = -N, n;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    int area = (maxx - minx) * (maxy - miny);
    if (area == 0)
        cout << -1;
    else
        cout << area;

    return 0;
}