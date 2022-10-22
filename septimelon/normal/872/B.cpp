#include <bits/stdc++.h>

using namespace std;

void smin(int& x, int& y) {
    if (x > y) {
        swap(x, y);
    }
}

void smax(int& x, int& y) {
    if (x < y) {
        swap(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, n;
    cin >> n >> k;
    int first;
    int last;
    int ma = (int)-1e9-1;
    int mi = (int)1e9+1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i == 0) {
            first = a;
        }
        if (i + 1 == n) {
            last = a;
        }
        mi = min(a, mi);
        ma = max(a, ma);
    }
    if (k == 1) {
        cout << mi << '\n';
        return 0;
    }
    if (k > 2) {
        cout << ma << '\n';
        return 0;
    }
    cout << max(first, last) << '\n';

    return 0;
}