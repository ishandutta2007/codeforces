#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    bool a[10] = {};
    while (n > 0) {
        if (a[n%10])
            return false;
        a[n%10] = true;
        n /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    for (int i=l; i<=r; i++)
        if (check(i)) {
            cout << i << "\n";
            return 0;
        }
    cout << "-1\n";

    return 0;
}