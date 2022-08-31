#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
const int mod = 998244353;

int madd(int a, int b) {
    a = a + b;
    while (a < 0) a += mod;
    while (a >= mod) a -= mod;
    return a;
}

int mmul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int mpow(int a, int n) {
    int r = 1;
    for(; n; n >>= 1) {
        if (n&1) r = mmul(r, a);
        a = mmul(a, a);
    }
    return r;
}

int main() {
    setIO();
    int n; cin >> n;
    int r = 0;
    for (int k = 1; k <= n; k++) {
        r = 0;
        if (k == n) {
            r = madd(r, 10);
        } else if (k == n - 1) {
            r = madd(r, 180);
        } else {
            r = madd(r, mmul(2, mmul(9, mpow(10, n-k))));
            r = madd(r, mmul((n-k-1), mmul(9, mmul(9, mpow(10, n-k-1)))));
        }
        cout << r << endl;
    }
    
    return 0;
}