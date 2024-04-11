#include <bits/stdc++.h>
using namespace std;

int a[200000];

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
        for (int i=0; i<n; i++)
            cin >> a[i];

        bool ok = false;
        for (int i=0; i<n-1; i++)
            if (abs(a[i] - a[i+1]) >= 2) {
                ok = true;
                cout << "YES\n" << i+1 << " " << i+2 << "\n";
                break;
            }

        if (!ok)
            cout << "NO\n";
    }

    return 0;
}