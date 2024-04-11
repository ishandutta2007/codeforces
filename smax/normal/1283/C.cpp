#include <bits/stdc++.h>
using namespace std;

int f[200000];
bool received[200000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> f[i];
        if (f[i] != 0)
            received[f[i]-1] = true;
    }

    int j = 0, last;
    for (int i=0; i<n; i++)
        if (f[i] == 0) {
            int start = j;
            bool ok = true;
            while (received[j] || j == i) {
                j = (j + 1) % n;
                if (j == start) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                f[i] = f[last];
                f[last] = i + 1;
            } else
                f[i] = j + 1;
            received[j] = true;
            last = i;
        }

    for (int i=0; i<n; i++)
        cout << f[i] << " ";
    cout << "\n";

    return 0;
}