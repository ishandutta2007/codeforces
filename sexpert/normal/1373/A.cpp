#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << ((a < c) ? 1 : -1) << " " << ((c < (ll)a * b) ? b : -1) << '\n';
    }
}