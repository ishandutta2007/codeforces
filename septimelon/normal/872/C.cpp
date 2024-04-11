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

void next() {
    int n;
    cin >> n;
    int ans = 0;
    if (n % 2 == 1) {
        n -= 9;
        ++ans;
    }
    if (n % 4 == 2) {
        n -= 6;
        ++ans;
    }
    if (n < 0) {
        cout << "-1\n";
        return;
    }
    ans += n / 4;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    
    for (int qq = 0; qq < q; ++qq) {
        next();
    }

    return 0;
}