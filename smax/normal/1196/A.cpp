#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        long long a[3];
        cin >> a[0] >> a[1] >> a[2];

        long long half = (a[0] + a[1] + a[2]) / 2;
        cout << half << "\n";
    }

    return 0;
}