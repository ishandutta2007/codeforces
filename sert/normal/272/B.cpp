#include <iostream>

using namespace std;

int f(int n) {
    if (n < 2) return n;
    return f(n / 2) + n % 2;
}

long long a[100], n, k, ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        a[f(k)]++;
    }
    for (int i = 0; i < 100; i++) ans += (a[i] * a[i] - a[i]) / 2;
    cout << ans;
    return 0;
}