#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int g = 3;
const int ALF = (1 << 20) - 3;
const int N = 2e5 + 13;
//const int N = 20 + 13;
const int K = 2e5 + 13;
//const int K = 20 + 13;
const int LOGN = 23;
const ld PI = acos(-1);
const ld eps = 1e-4;
const int S = 1007;
//const int B = 100;

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

void solve() {
    li a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a * d == b * c) {
        cout << 0 << endl;
        return;
    }

//    cout << (b != 0 && a * d % b == 0) << (c != 0 && a * d % c == 0) << (d != 0 && b * c % d == 0) << (a != 0 && b * c % a == 0) << endl;

//    if(b != 0 && a * d % b == 0 || c != 0 && a * d % c == 0 || d != 0 && b * c % d == 0 || a != 0 && b * c % a == 0)
    if(b != 0 && c != 0&& a * d % (b * c) == 0 || a != 0 && d != 0 && b * c % (a * d) == 0)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}