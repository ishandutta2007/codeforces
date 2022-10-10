#include <bits/stdc++.h>
using namespace std;

int a[3000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a + n);
    int ret = 0;
    for (int i=0; i<n; i++)
        if (i > 0 && a[i] <= a[i-1]) {
            ret += a[i-1] + 1 - a[i];
            a[i] = a[i-1] + 1;
        }

    cout << ret << "\n";

    return 0;
}