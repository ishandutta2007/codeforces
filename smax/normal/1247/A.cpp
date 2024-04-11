#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    if (a == b)
        cout << a << "0 " << b << "1\n";
    else if (b - a == 1)
        cout << a << "9 " << b << "0\n";
    else if (a == 9 && b == 1)
        cout << "99 100\n";
    else
        cout << "-1\n";

    return 0;
}