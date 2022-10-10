#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;

        if (a > b)
            swap(a, b);
        int ret = max(min(b, c - r) - a, 0);
        if (b > c + r)
            ret += b - max(a, c + r);

        cout << ret << "\n";
    }

    return 0;
}