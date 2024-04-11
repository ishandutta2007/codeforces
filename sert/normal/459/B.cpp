#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

long long a[300000];
long long n, u1, u2;

int main() {
    ///freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (a[n - 1] == a[0]) {
        cout << "0 " << (n - 1) * n / 2;
        return 0;
    }
    for (u1 = 0; a[u1] == a[0]; u1++);
    for (u2 = n - 1; a[u2] == a[n - 1]; u2--);
    cout << a[n - 1] - a[0] << " " << u1 * (n - 1 - u2);
    return 0;
}