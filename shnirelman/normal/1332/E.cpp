#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

const int N = 2e5 + 13;
const int M = 998244353;

int norm(int a) {
    while(a >= M)
        a -= M;

    while(a < 0)
        a += M;

    return a;
}

int pow2(int n, li k) {
//    cout << n << ' ' << k << endl;
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);

    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

void solve() {
//    cout << pow2(2, M - 2) << endl;
//    cout << pow2(2, M - 2) * 2 % M << endl;
//    cout << pow2(2, M - 1)  << endl;
//    cout << pow2(3, 3) << endl;

    int l, r, n, m;
    cin >> n >> m >> l >> r;

    if(n * 1ll * m % 2 == 1) {
        cout << pow2(r - l + 1, n * 1ll * m);
        exit(0);
    }

    int len = r - l + 1;

    int x0, x1;
    x0 = x1 = len / 2;

    if(len % 2 == 1) {
        if(l % 2 == 1)
            x1++;
        else
            x0++;
    }

    int a = norm(x1 + x0);
    int b = norm(x0 - x1);

//    cout << x1 << ' '<< x0 << ' ' << a << ' ' << b << endl;
//    cout << pow2(a, n * 1ll * m) << ' ' << pow2(b, n * 1ll * m) << endl;

    int sum = norm(pow2(a, n * 1ll * m) + pow2(b, n * 1ll * m));
//    cout << sum << endl;
//    cout << pow2(2, M - 2) << endl;
    cout << sum * 1ll * pow2(2, M - 2) % M;
}

int main() {
    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}