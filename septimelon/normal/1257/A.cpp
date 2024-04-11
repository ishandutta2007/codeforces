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
        int n;
        cin >> n;
        int x, a, b;
        cin >> x >> a >> b;
        --a; --b;
        smin(a, b);
        if (b - a + x >= n - 1) {
            cout << n - 1 << '\n';
        } else {
            cout << b - a + x << '\n';
        }
    }

    return 0;
}