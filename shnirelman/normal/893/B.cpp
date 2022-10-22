#include <bits/stdc++.h>

using namespace std;
using li = long long;
using ld = long double;

int main() {
    int n;
    cin >> n;

    int ans = 1;
    for(int i = 0; (1 << (2 * i)) <= n; i++) {
        int p = (1 << i);
        int d = p * (p * 2 - 1);
        if(n % d == 0) {
            ans = d;
        } else if(d > n)
            break;
    }

    cout << ans;
}