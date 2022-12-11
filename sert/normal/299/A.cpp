#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[100004];
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    if (a[i] % a[0]) {
        cout << -1;
        return 0;
    }
    cout << a[0];

    return 0;
}