#include <iostream>

using namespace std;

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

int minv(int a) {
    return mpow(a, mod-2);
}

int mdiv(int a, int b) {
    return mmul(a, minv(b));
}

int main(){
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int bc = 0;
    for (int i = 0; i < m; i++)
        bc += b[i] - '0';
    int res = 0;
    int a2 = 1;
    for (int ap = n - 1, bp = m - 1; ap >= 0 && bp >= 0; ap--, bp--) {
        if (a[ap] == '1')
            res = madd(res, mmul(a2, bc));
        bc -= b[bp] - '0';
        a2 = mmul(a2, 2);
    }
    cout << res << endl;
    return 0;
}