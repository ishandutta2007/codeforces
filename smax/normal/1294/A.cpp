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
        long long a, b, c, n;
        cin >> a >> b >> c >> n;

        if ((a + b + c + n) % 3 == 0 && (a + b + c + n) / 3 >= max({a, b, c}))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}