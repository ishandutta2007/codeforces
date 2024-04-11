#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if(a > b)
            swap(a, b);
        int x = c - r, y = c + r;
        cout << b - a - max(0, min(b, y) - max(a, x)) << '\n';
    }
}