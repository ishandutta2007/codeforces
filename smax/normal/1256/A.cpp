#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int a, b, n, s;
        cin >> a >> b >> n >> s;

        if (b >= (b % n - s % n + n) % n && (s - (b - (b % n - s % n + n) % n)) / n <= a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}