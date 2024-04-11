#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;
int dpeven[300009], dpodd[300009];

int binpow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x % 2) {
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dpeven[0] = 1;
    dpodd[1] = 1;
    for (int i = 2; i <= 200009; i++) {
        if (i % 2) {
            dpodd[i] = (M + dpodd[i - 2] + dpeven[i - 1]) % M;
        } else {
            dpeven[i] = (M + dpeven[i - 2] + dpodd[i - 1]) % M;
        }
    }
    int n;
    cin >> n;
    if (n == 1) {
        cout << binpow(2, M - 2) << '\n';
    } else if (n % 2) {
        cout << (M + dpodd[n] - dpodd[n - 2]) % M * binpow(2, n * (M - 2)) % M << '\n';
    } else {
        cout << (M + dpeven[n] - dpeven[n - 2]) % M * binpow(2, n * (M - 2)) % M << '\n';
    }
}