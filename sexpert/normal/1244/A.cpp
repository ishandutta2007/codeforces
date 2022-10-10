#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1)/c, y = (b + d - 1)/d;
        if(x + y <= k)
            cout << x << " " << y << '\n';
        else
            cout << "-1\n";
    }
}