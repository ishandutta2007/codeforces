#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
//const int M = 998244353;
const int M = 32768;
const int N = 5e5 + 13;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

/*
*/

void solve() {
    li n;
    cin >> n;

    li x = n;
    while(x % 2 == 0) {
        x /= 2;
    }

    li pw2 = n / x;

    if((pw2 * 2 + 1) <= x) {
        cout << pw2 * 2 << endl;
    } else {
        for(li k = 1; k * k <= x; k++) {
            if(k > 1 && n >= (k + 1) * k / 2 && (n - (k + 1) * k / 2) % k == 0) {
                cout << k << endl;
                return;
            }

            li m = x / k;
            if(m > 1 && n >= (m + 1) * m / 2 && (n - (m + 1) * m / 2) % m == 0) {
                cout << m << endl;
                return;
            }
        }
        cout << -1 << endl;
    }

//    cout << (x > 1 ? x : -1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}