#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double solve(double V, double B) {
    if(V < 1e-7) return B;
    return V / (floor(V / B));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ll A, B;

    cin >> A >> B;

    if (A < B) {
        cout << -1 << "\n";
        return 0;
    }

    cout << min(solve((A+B)/2.0, B), solve((A-B)/2.0, B)) << "\n";
}