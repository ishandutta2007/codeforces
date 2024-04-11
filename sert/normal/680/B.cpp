#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000 + 34;
typedef long double ld;

int n, a[N], p, l, r, sum;

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    l = p - 2;
    r = p;
    while (l >= 0 && r < n) {
        if (a[l] + a[r] == 1)
            sum--;
        l--;
        r++;
    }
    cout << sum;
    return 0;
}