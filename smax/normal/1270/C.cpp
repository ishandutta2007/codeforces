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

        long long s = 0, x = 0;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            s += a;
            x ^= a;
        }

        cout << "2\n" << x << " " << s + x << "\n";
    }

    return 0;
}