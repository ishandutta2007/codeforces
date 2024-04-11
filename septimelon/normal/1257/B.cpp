#include <bits/stdc++.h>

using namespace std;

void smin(int& x, int& y) {
    if (y < x) {
        swap(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        int x, y;
        cin >> x >> y;
        if (x <= 3 && y > 3) {
            cout << "NO\n";
        } else if (x > 1 || x == y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}