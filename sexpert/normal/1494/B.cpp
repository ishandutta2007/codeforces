#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(int n, int u, int r, int d, int l) {
    for(int ms = 0; ms < 16; ms++) {
        int ul = (ms & 1), ur = ((ms >> 1) & 1), dl = ((ms >> 2) & 1), dr = ((ms >> 3) & 1);
        int U = u - ul - ur, R = r - ur - dr, D = d - dl - dr, L = l - ul - dl;
        if(U < 0 || R < 0 || D < 0 || L < 0 || U > n - 2 || R > n - 2 || D > n - 2 || L > n - 2)
            continue;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        cout << (solve(n, a, b, c, d) ? "YES\n" : "NO\n");
    }
}