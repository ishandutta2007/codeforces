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
        int n;
        cin >> n;

        set<int> lessThanX, lessThanY;
        set<int, greater<int>> greaterThanX, greaterThanY;
        for (int i=0; i<n; i++) {
            int x, y, f[4];
            cin >> x >> y >> f[0] >> f[1] >> f[2] >> f[3];
            if (f[0] == 0)
                greaterThanX.insert(x);
            if (f[1] == 0)
                lessThanY.insert(y);
            if (f[2] == 0)
                lessThanX.insert(x);
            if (f[3] == 0)
                greaterThanY.insert(y);
        }

        int x = 0, y = 0;
        if (greaterThanX.empty() && !lessThanX.empty()) {
            x = *lessThanX.begin();
        } else if (!greaterThanX.empty() && lessThanX.empty()) {
            x = *greaterThanX.begin();
        } else if (!greaterThanX.empty() && !lessThanX.empty()) {
            x = *greaterThanX.begin();
            if (x > *lessThanX.begin()) {
                cout << "0\n";
                continue;
            }
        }

        if (greaterThanY.empty() && !lessThanY.empty()) {
            y = *lessThanY.begin();
        } else if (!greaterThanY.empty() && lessThanY.empty()) {
            y = *greaterThanY.begin();
        } else if (!greaterThanY.empty() && !lessThanY.empty()) {
            y = *greaterThanY.begin();
            if (y > *lessThanY.begin()) {
                cout << "0\n";
                continue;
            }
        }
        cout << "1 " << x << " " << y << "\n";
    }

    return 0;
}