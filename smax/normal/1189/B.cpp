#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a + n);
    if (a[n-1] < a[n-2] + a[n-3]) {
        cout << "YES" << endl << a[n-1] << " ";
        for (int i=n-3; i>=0; i--)
            cout << a[i] << " ";
        cout << a[n-2] << endl;
    } else
        cout << "NO" << endl;

    return 0;
}