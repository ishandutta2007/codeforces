#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000 + 34;
typedef long double ld;

int n, a[N], sum, df;

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + 5);
    for (int i = 1; i < 5; i++)
        if (a[i] == a[i - 1])
            df = max(df, 2 * a[i]);
    for (int i = 2; i < 5; i++)
        if (a[i] == a[i - 2])
            df = max(df, 3 * a[i]);
    cout << sum - df;
    return 0;
}