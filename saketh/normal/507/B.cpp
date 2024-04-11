#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ll R, X1, Y1, X2, Y2;

    cin >> R >> X1 >> Y1 >> X2 >> Y2;

    ll dx = abs(X2 - X1);
    ll dy = abs(Y2 - Y1);

    ll d2 = dx * dx + dy * dy;

    cout << int(ceil(sqrt(d2)/(2 * R))) << "\n";
}