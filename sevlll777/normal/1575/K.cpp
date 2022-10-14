#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

const int mod = (int) 1e9 + 7;

int pow_(int n, int power) {
    if (power == 0) {
        return 1;
    }
    if (power % 2) {
        return n * pow_(n, power - 1) % mod;
    }
    int val = pow_(n, power / 2);
    return val * val % mod;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int sq = (n * m - r * c);
    if (ax == bx && ay == by) {
        sq = n * m;
    }
    int res = pow_(k, sq);
    cout << res << '\n';
}