#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    LL n;
    cin >> n;
    if (n == 1) {
        cout << 3 << endl;
    } else {
        cout << 4 + (4 * n - 3) / 3 << endl;
    }
}