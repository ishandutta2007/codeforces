#include <bits/stdc++.h>
using namespace std;

int c[1000], ret[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, d, plankSize = 0;
    cin >> n >> m >> d;
    for (int i=0; i<m; i++) {
        cin >> c[i];
        plankSize += c[i];
    }

    int gapSize = n - plankSize;
    if (d == 1 && gapSize == 0) {
        cout << "YES\n";
        for (int i=0; i<m; i++)
            for (int j=0; j<c[i]; j++)
                cout << i+1 << " ";
        cout << "\n";
    } else if (d == 1 && gapSize > 0 || gapSize / (d - 1) + (gapSize % (d - 1) > 0) > m + 1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        int i = 0, j = 0;
        while (i < n) {
            int stepSize = min(d - 1, gapSize);
            gapSize -= stepSize;
            while (stepSize--) {
                cout << "0 ";
                i++;
            }
            while (c[j]--) {
                cout << j+1 << " ";
                i++;
            }
            j++;
        }
        cout << "\n";
    }

    return 0;
}