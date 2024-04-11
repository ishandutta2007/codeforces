#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    n /= 2;
    if((x == n || x == n + 1) && (y == n || y == n + 1))
        cout << "NO\n";
    else
        cout << "YES\n";
}