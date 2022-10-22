#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int r = 0; r < t; r++) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int sorted[n];
        bool b[n];

        for (int i = 0; i < n; i++) {
            b[i] = false;
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sorted[i] = a[i];
        }

        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;

            b[k - 1] = true;
        }
        sort(sorted, sorted + n);
        bool an = false;
        for (int i = 0; i < n; i++) {
            int now = sorted[i];
            if (a[i] == sorted[i])
                continue;
            int j;
            bool found = false;
            for (j = i + 1; j < n; j++) {
                if (a[j] == sorted[i]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
//                cout << "there is a bug" << endl;
            }

            for (int k = j - 1; k >= i; k--) {
                if (b[k]) {
                    swap(a[k], a[k + 1]);
                } else {
                    cout << "NO" << endl;
                    an = true;
                    break;
                }
            }

            if (an) {
                break;
            }
        }

        if (!an) {
            cout << "YES" << endl;
        }
    }
    return 0;
}