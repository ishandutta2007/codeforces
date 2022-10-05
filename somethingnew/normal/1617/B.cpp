#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#define all(a) (a).begin(), (a).end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << ' ' << n / 2 - 1 << ' ' << 1 << '\n';
    } else {
        if (n / 2 % 2 == 1)
            cout << n / 2 - 2 << ' ' << n / 2 + 2 << ' ' << 1 << '\n';
        else
            cout << n / 2 - 1 << ' ' << n / 2 + 1 << ' ' << 1 << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
}
/*
1 2
RL
DU
LR
10
v 1 1
v 1 2
v 1 3
v 2 1
v 2 2
v 2 3
h 1 1
h 2 1
h 3 1
h 4 1

 */