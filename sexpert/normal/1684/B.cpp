#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << b*c + a << " " << b << " " << c << '\n';
    }
}