#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0, a[100500];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    if (a[i] <= a[i - 1]) {
        ans += a[i - 1] - a[i] + 1;
        a[i] = a[i - 1] + 1;
    }
    cout << ans;
    return 0;
}