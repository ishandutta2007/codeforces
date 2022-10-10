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
        int n;
        cin >> n;

        bool ok = true;
        int a = 2, b, c;
        while (n % a != 0 && a * a <= n)
            a++;
        if (a * a > n)
            ok = false;
        else {
            n /= a;
            b = a + 1;
            while (n % b != 0 && b * b <= n)
                b++;
            if (b * b > n)
                ok = false;
            else {
                c = n / b;
                if (c < 2 || c == a || c == b)
                    ok = false;
            }
        }

        if (ok)
            cout << "YES\n" << a << " " << b << " " << c << "\n";
        else
            cout << "NO\n";
    }

    return 0;
}