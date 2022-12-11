#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

ll n, x, y;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> x >> y;

    if (n - 1 + (y - n + 1) * (y - n + 1) < x || n > y)
        cout << -1;
    else {
        for (int i = 1; i < n; i++)
            cout << "1 ";
        cout << y - n + 1;
    }

    return 0;
}