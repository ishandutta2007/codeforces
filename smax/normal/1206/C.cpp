#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i=0; i<n; i++) {
            if (i % 2 == 0)
                cout << 2 * i + 1 << " ";
            else
                cout << 2 * i + 2 << " ";
        }
        for (int i=0; i<n; i++) {
            if (i % 2 == 0)
                cout << 2 * i + 2 << " ";
            else
                cout << 2 * i + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}