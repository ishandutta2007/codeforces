#include <bits/stdc++.h>
using namespace std;
const int N = 190;
typedef long long ll;

int x, a, b, n;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1)
            a = i + 1;
        if (x == n)
            b = i + 1;
    }
    cout << max(max(a - 1, n - a), max(b - 1, n - b));

    return 0;
}