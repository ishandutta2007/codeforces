#include <bits/stdc++.h>
using namespace std;
int n, cur, s1, s2;
bool u;
int main() {
    long long l, r, k, st = 1;
    cin >> l >> r >> k;
    while (true) {
        if (l <= st && st <= r) {
            u = true;
            cout << st << " ";
        }
        if (st > r / k)
            break;
        st *= k;
    }
    if (!u)
        cout << "-1";
}