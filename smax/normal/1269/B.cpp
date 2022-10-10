#include <bits/stdc++.h>
using namespace std;

int a[2000], b[2000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int ret = INT_MAX;
    for (int i=0; i<n; i++) {
        bool ok = true;
        int x = (b[0] - a[0] + m) % m;
        for (int j=1; j<n; j++)
            if ((b[j] - a[j] + m) % m != x) {
                ok = false;
                break;
            }
        if (ok)
            ret = min(ret, x);
        rotate(b, b + 1, b + n);
    }

    cout << ret << "\n";

    return 0;
}