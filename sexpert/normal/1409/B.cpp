#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        if(a > b || (a == b && x > y)) {
            swap(a, b);
            swap(x, y);
        }
        if(n <= a - x)
            cout << (a - n) * b << '\n';
        else
            cout << min(x * max(y, b - (n - (a - x))), max(y, b - n) * max(x, a - (n - min(b - y, n)))) << '\n';
    }
}